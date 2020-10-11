`timescale 1ns / 1ps


module BlockRAM
(
    input [18:0]    RAMR_ReadAddr,
    output [7:0]    RAMR_ReadData,
    
    input [7:0]     RAMW_WriteData,
    input [18:0]    RAMW_WriteAddr,
    
    input           RAMW_WriteEn,
            
    input           ADC_Sampleclock,          
    input           clk,
    input           reset
);

    reg [7:0]       storage[(1<<19)-1:0];   // 2^19 = 524288
    
    assign RAMR_ReadData = storage[RAMR_ReadAddr];  //Always read
    
    always @ (posedge clk)
    begin
        if (RAMW_WriteEn)
        begin
            storage[RAMW_WriteAddr]   <= RAMW_WriteData;             
        end
    end
endmodule
