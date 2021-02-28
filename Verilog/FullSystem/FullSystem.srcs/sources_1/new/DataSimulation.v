`timescale 1ns / 1ps

module DataSimulation(
    input clk,
    input ADC_SampleClock,
    input reset,
    output reg [9:0] SimData
    );
   
    wire ADC_SampleClock_posedge_pulse;
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;   
   
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            SimData <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin
                if (SimData > 100)
                begin
                    SimData <= 0;
                end
                else
                begin
                    SimData <= SimData + 1;
                end
            end
        end
    end
    
endmodule
