`timescale 1ns / 1ps


module Regs(
    input clk,
    input [7:0] Write_Data,
    input WrEn,
    input RdEn,
    input [4:0] Regs_Addr,
    output reg [7:0] Read_Data
    );
    
    reg [7:0] registers [4:0];
    //Make these 'define
    initial //This is bad form
    begin
        registers[0] = 8'b01000010; //B
        registers[1] = 8'b01000011; //C
        registers[2] = 8'b01010011; //S
        registers[3] = 8'b00000001; //RevId
        registers[4] = 8'b01010010; //scratch R/W reg
    end
    always @(posedge clk)
    begin
        if (WrEn)
        begin 
            registers[Regs_Addr] <= Write_Data;
        end
    end
    always @(*)
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
    
endmodule
