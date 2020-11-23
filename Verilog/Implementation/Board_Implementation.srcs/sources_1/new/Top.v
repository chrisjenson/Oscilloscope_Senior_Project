`timescale 1ns / 1ps

module Top(
    input reset,
    input MOSI_Raw,
    input SlaveSel,
    input clk_in1,
    input SCLK_Raw,
    output MISO
    );
    
    wire clk;
    wire locked;
    
    SPI u_SPI(
        .MISO(MISO),
        .MOSI_Raw(MOSI_Raw),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .reset(reset),
        .SCLK_Raw(SCLK_Raw)
        
        //For RAM
        //.Buffer_DataIn(), //DEBUG Changed this to 16 bits
        //.FIFO_OutRTR()
    );
    
    clk_wiz_0 CLKWIZ0(.clk_out1(clk), .reset(reset), .locked(locked), .clk_in1(clk_in1));
    
endmodule
