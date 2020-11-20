`timescale 1ns / 1ps

module RAM_AddrGen(
    input clk,
    input reset,
    input ADC_SampleClock,
    input [7:0] Buffer_DataIn,
    output reg [18:0] RAMW_WriteAddr, //Port A on RAM
    output reg [7:0] RAMW_Data
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
    begin
    //Write data to RAM
    //Inputs
        //Reset
    //Outputs
        //RAMW_WriteAddr
        begin
            if (reset)
            begin
                RAMW_WriteAddr <= 0;
            end
            else
            begin
                if (ADC_SampleClock_posedge_pulse) //Buffer_DataIn in is set on negedge
                begin
                    RAMW_Data <= Buffer_DataIn;
                    RAMW_WriteAddr <= RAMW_WriteAddr + 1;
                end
            end
        end
    end
    
    
    BlockRam u_BlockRam(
        //PORT A
        .addra(RAMW_WriteAddr),
        .ena(),
        .clka(clk), 
        .dina(RAMW_Data),
        .wea(), //DEBUG: WHAT IS THIS??????
        //PORT B
        .clkb(clk), 
        .doutb(),
        .addrb()
    );
    
endmodule