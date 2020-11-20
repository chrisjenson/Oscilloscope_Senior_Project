`timescale 1ns / 1ps

module ADCInterface(
    input               clk, //from tb
    input               reset, //from tb
    input               ADC_SampleClock, //from timing gen
    input [9:0]         ADC_DataIn, //from DAB
    output reg [7:0]    Buffer_DataIn
    );
    /////////////////////////////////////////////////
    //Get negedge and posedge pulses
    wire ADC_SampleClock_posedge_pulse;
    wire ADC_SampleClock_negedge_pulse;
    
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;
    assign ADC_SampleClock_negedge_pulse = ~ADC_SampleClock & ADC_SampleClock_p1;
    //End section
    //////////////////////////////////////////////////////////////    
    
    always @(posedge clk)
    //Select 8 bits from input data as output on negedge of sample clk
    //Inputs
        //reset
        //ADC_SampleClock_negedge_pulse
        //ADC_DataIn
    //Outputs
        //Buffer_DataIn
    begin
        if (reset)
        begin
            Buffer_DataIn <= 0;
        end
        else
        begin
            if (ADC_SampleClock_negedge_pulse)
            begin
                Buffer_DataIn <= ADC_DataIn[9:2]; //DBEUG: MAKE THESE BITS SELECTABLE
            end
        end
    end
    
    
//    TimingGen u_TimingGen(
//        .ADC_SampleClock(ADC_SampleClock)
//    );
    
endmodule
