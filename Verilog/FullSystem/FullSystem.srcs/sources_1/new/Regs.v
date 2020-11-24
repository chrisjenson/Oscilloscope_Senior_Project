`timescale 1ns / 1ps


module Regs(
    input clk,
    input reset,
    input [7:0] Write_Data,
    input WrEn,
    input RdEn,
    input [4:0] Regs_Addr,
    output reg [7:0] Read_Data,
    //For debug
    output [7:0] DebugRegister
    );
    
    
    
    reg [7:0] registers [13:0];
    assign DebugRegister = registers[4];
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            registers[0] <= 8'b01000010; //B
            registers[1] <= 8'b01000011; //C
            registers[2] <= 8'b01010011; //S
            registers[3] <= 8'b00000011; //RevId
            registers[4] <= 8'b01010101; //scratch R/W reg- Debug register
            registers[5] <= 8'b00000001; //Trigger
            registers[6] <= 8'b00000000; //Trigger slope
            registers[7] <= 8'b00000000; //Sample Rate
            registers[8] <= 8'b00000000; //on-bit
            registers[9] <= 8'b00000000; //reset
            registers[10] <= 8'b00000000; //IRS_High
            registers[11] <= 8'b00000000; //IRS_Low
            registers[12] <= 8'b00000000; //Offset
            registers[13] <= 8'b00000000; //Shift Control Register
        end
    end
    always @(posedge clk)
    begin
        if (!reset)
        begin
            if (WrEn)
            begin 
                registers[Regs_Addr] <= Write_Data;
            end
        end
    end
    always @(*)
    begin
        if (!reset)
        begin
            if (RdEn)
            begin
                Read_Data = registers[Regs_Addr];
            end
            else//Always give a value in a combinational block!!
            begin
                Read_Data = 8'b00000000;
            end
        end
    end
    
endmodule
