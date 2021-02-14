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
    
    
    
    reg [7:0] registers [4:0];
    assign DebugRegister = registers[4];
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            registers[0] <= 8'b00000000;//01000010; //B
            registers[1] <= 8'b00000001; //C
            registers[2] <= 8'b00000010; //S
            registers[3] <= 8'b00000011; //RevId
            registers[4] <= 8'b01010101; //scratch R/W reg
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