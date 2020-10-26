`timescale 1ns / 1ps

module SPI(
        input [15:0] SPIWord,
        input MISOMOSI,
        input SlaveSel,
        input SPIclk,
        output reg [7:0] dataOut
    );
     
    reg [2:0] cmd;
    reg [4:0] params;
    reg [7:0] data;
    
    reg WrEn;
    reg RdEn;
    
    assign cmd = SPIWord[15:13];
    assign params = SPIWord[12:8];
    assign data = SPIWord[7:0];
    
    always @(*)
    begin
        case (cmd)
            3'b000: //ReadReg
            begin
                RdEn = 1;
                WrEn = 0;
            end
            3'b001: //Write
            begin
                RdEn = 0;
                WrEn = 1;
            end
            3'b010: //ReadData
            begin
                RdEn = 0;
                WrEn = 0;
            end
        
        endcase
    
    end
     
     
    Regs(
        .Write_Data(data),
        .Write_Addr(params),
        .WrEn(WrEn),
        .RdEn(RdEn),
        .Read_Addr(params),
        .Read_Data(dataOut)
    );
endmodule
