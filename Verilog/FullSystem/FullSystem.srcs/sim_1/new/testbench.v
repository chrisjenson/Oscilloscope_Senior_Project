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
    //Obsolete due to DataSimulation Module
    /*
    `define numInputs     (16384)
    
    wire [9:0] stimInData; //
    reg [13:0] stimInCount; //2^14 = 16384
    reg [9:0] stimData [`numInputs-1:0];
    
     assign stimInData = stimData[stimInCount];
    
    integer i;
    initial
    begin
        //Initialize with random data
        for (i = 0; i < `numInputs; i = i + 1)
        begin
            stimData[i] = $random();
        end
    end
    
    //End intialize data
    ///////////////////////////////////
    
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            stimInCount <= 0;
        end
    end
    
    always @(posedge ADC_SampleClock)
    //After ADC Sampling, go to next adc input
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
    */
    
    wire ADC_SampleClock; //Input from Timing Gen

    ////////////////////////////////////////////////////////////
    //SPI TB
    
    reg SCLK;
    reg [1:0] SCLKCount;
    
    reg MISO;
    reg MOSI;
    reg SlaveSel;

    wire [15:0] command;
    reg [3:0] index;
    reg commandDone;
    reg [5:0] commandNum;
    reg [15:0] commandArray[4:0];
    initial
    begin
        SlaveSel <= 1;
        SCLK = 1;
        SCLKCount = 0;
        index = 15;
    end
    
    initial 
    begin
        commandDone <= 0;
        commandNum <= 0;
    end
    
    initial
    begin  
        commandArray[0] = 16'b0000000000000000;
        commandArray[1] = 16'b0000000000000000;
        //commandArray[1] = 16'b0100011000000001; //trigger on falling edge
        commandArray[2] = 16'b0110110111111111; //cmd = Read Ram
        commandArray[3] = 16'b0000000000000000;                                      //If changing number of data points being read (1024) need to change OneZeroTwoFourCounter below
        //commandArray[4] = 16'b0110110111111111; //cmd = Read, params = 4, data = x
        //commandArray[5] = 16'b0110110111111111; //cmd = write, params = 4, data = 8'hF0
        commandArray[6] = 16'b0000000000000000;
        commandArray[7] = 16'b0000000000000000;
        

    end 
    
    always @(posedge clk) 
    //Simluate Slave Clock
    begin
        if (!reset)
        begin
            if (!SlaveSel)
            begin
                SCLKCount <= SCLKCount + 1;
                if (SCLKCount == 2'b01)
                begin
                    #1 SCLK = ~SCLK;
                end
            end
        end
    end
    
    initial 
    //Initialize
    begin
        #50 //Begin spi after 50
        SlaveSel <=0;
        reset <= 0;
    end
    
    always @(posedge clk)
    //If command finished, go to next command
    begin
        if (!reset)
        begin
        if (commandDone)
            begin
                commandDone <= 0;
                #100;
                if (commandNum == 3)
                begin
                 //   reset <= 1;
                 //   #10
                //    reset <= 0;
                end
                commandNum <= commandNum + 1;
                SlaveSel <= 0;
            end
        end
    end
    
    assign command = commandArray[commandNum];
    reg [6:0] OneTwentyEightCounter; //128
    reg [9:0] RAMReadCounter; //1024


    always @(posedge SCLK)
    //Simulates SPI Master
    //Inputs:
        //SlaveSel
        //Command
    //Outputs:
        //MOSI
        //Index (initial = 15)
    begin
        if (!reset)
        begin
            if (!SlaveSel)
            begin
                if (command[15:13] == 3'b011) //If RAM Read
                begin
                    MOSI <= command[index];
                    if (index == 0)
                    begin //For testing, read 1024 data values.
                        index <= 15;
                        if (RAMReadCounter == 31) //# TRANSFERS OF 16 sets OF DATA
                        begin
                            #40 //wait 40 after ram read is done
                            SlaveSel <= 1;
                            commandDone <= 1;
                            RAMReadCounter <= 0;
                        end
                        else
                        begin
                            RAMReadCounter <= RAMReadCounter + 1;
                        end
                    end
                    else
                    begin
                        index <= index - 1;
                    end
                end
                else if (command[15:13] == 3'b000)
                begin
                    //IDLE
                    #40 
                    SlaveSel <= 1;
                    commandDone <= 1;
                    index <= 15;
                    //commandNum <= 0;
                end
                else if ((command[15:13] == 3'b001) ||  (command[15:13] == 3'b010)) //REG READ/WRITE
                begin
                    MOSI <= command[index];
                    index <= index - 1;
                    if (index == 0)
                    begin
                        #40 
                        SlaveSel <= 1;
                       // commandNum <= commandNum + 1;
                        commandDone <= 1;
                        index <= 15;
                    end
                end
                else //IDLE
                begin
                     //Commands done... Idle
                    #40 
                    SlaveSel <= 1;
                    //commandDone <= 1;
                    index <= 15;
                    //commandNum <= 0;
                end
            end
            else
            //If SS is high
            begin
                MOSI <= 0;
                index <= 15;
                OneTwentyEightCounter <= 0;
                RAMReadCounter <= 0;

                //commandDone <= 1;
            end
        end
        else
        begin
            RAMReadCounter <= 0;
        end
    end
    
     //Simulate data input on hardware
    wire [9:0] ADC_InData;
    
    DataSimulation u_DataSimulation(
        .ADC_SampleClock(ADC_SampleClock),
        .clk(clk),
        .reset(reset),
        .SimData(ADC_InData)
    );
    /////////////////////
    
    
    
    Top u_Top(
        .clk(clk),
        .rst_(~reset),
        //SPI
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .SCLK_Raw(SCLK),
        //ADC Interface
        //.ADC_InData(ADC_InData),
        .ADC_SampleClock(ADC_SampleClock)
    );
endmodule
