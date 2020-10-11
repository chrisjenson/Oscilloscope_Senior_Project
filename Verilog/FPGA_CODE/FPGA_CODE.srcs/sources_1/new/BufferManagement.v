`timescale 1ns / 1ps

module BufferManagement(
    input [7:0]     Buffer_DataIn,
    
    input [7:0]     RAMR_ReadData,

    output [7:0]    RAMW_WriteData,
    
    input [1:0]     Regs_SampleRate,
    
    input           triggered,
    
    input           ADC_Sampleclock,
    input           reset
    );
    
    always @(posedge ADC_Sampleclock)
    begin
        if (triggered)
        begin
            //send data to spi
        end
        
    end
    
endmodule




