`timescale 1ns / 1ps


module Regs(
    input [7:0] Write_Data,
    input [4:0] Write_Addr,
    input WrEn,
    input RdEn,
    input [4:0] Read_Addr,
    output reg [7:0] Read_Data
    );
    
    reg [7:0] registers [1:0];
    
    assign registers[0] = 8'b10101010;
    assign registers[1] = 8'b01010101;
    assign registers[2] = 8'b00001111;
    assign registers[3] = 8'b11110000;
    
    always @(*)
    begin
        if (WrEn)
        begin
            registers[Write_Addr] = Write_Data;
        end
        else if (RdEn)
        begin
            Read_Data = registers[Read_Addr];
        end
        
    end
    
    
endmodule
