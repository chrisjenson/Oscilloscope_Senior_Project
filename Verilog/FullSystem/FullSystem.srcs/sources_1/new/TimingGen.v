`timescale 1ns / 1ps

module TimingGen(
    input clk, //from tb
    input reset, //from tb
    output reg ADC_SampleClock //To ADCInterface, DAB.
    );
    
    reg [1:0] twoCounter;
    
    always @(posedge clk)
    begin
    //Generates a 25MHz sample clock
    //Inputs
        //Reset (Active Low)
    //Outputs  
        //ADC_SampleClock
        
        if (reset)
        begin
            ADC_SampleClock <= 0;
            twoCounter <= 0;
        end
        else
        begin
            if (twoCounter == 2'b01)
            begin
                ADC_SampleClock <= ~ADC_SampleClock;
                twoCounter <= 0;
            end
            else
            begin
                twoCounter <= twoCounter + 1;
            end
        end
    end

endmodule
