`timescale 1ns / 1ps

module testbench();
    
    reg clk;
    reg reset;
    
    initial
    //Generate
    begin
        clk = 0;
        while(1)
        begin
            #5 clk = ~clk; //100MHZ clock. Board is capable of >450MHz
        end
    end
    
    initial
    //Initize reset
    begin
        reset = 1;
        #10 reset = 0;
    end
    
    /////////////////////
    //Initialize input Data
    `define numInputs     (4096)
    
    wire [9:0] stimInData;
    reg [11:0] stimInCount; //2^12 = 4096
    reg [9:0] stimData [`numInputs-1:0];
    
     assign stimInData = stimData[stimInCount];
    
    integer i;
    initial
    begin
        for (i = 0; i < `numInputs; i = i + 1)
        begin
            stimData[i] = $random();
        end
    end
    //End intialize data
    ///////////////////////////////////
    
    wire ADC_SampleClock; //Input from Timing Gen
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            stimInCount <= 0;
        end
    end
    
    always @(posedge ADC_SampleClock)
    //Inputs
        //Reset
    begin
        if (reset)
        begin
            stimInCount <= 0;
        end
        else
        begin
            stimInCount <= stimInCount + 1;
        end
    end
    wire onBit;
    assign onBit = ~reset;
    
    Top u_Top(
        .clk(clk),
        .reset(reset),
        .onBit(onBit),
        .stimInData(stimInData),
        .ADC_SampleClock(ADC_SampleClock)
    );
    
//    TimingGen u_TimingGen(
//        .clk(clk),
//        .reset(reset),
//        .ADC_SampleClock(ADC_SampleClock)
//    );
    
//    ADCInterface u_ADCInterface(
//        .clk(clk),
//        .reset(reset),      
//        .ADC_DataIn(stimInData), 
//        .ADC_SampleClock(ADC_SampleClock)
//    );
    
endmodule
