`timescale 1ns / 1ps

module Top(
    input rst_,
    input MOSI_Raw,
    input SlaveSel,
    input clk,
    input SCLK_Raw,
    output MISO,
    //For Debug
    output [7:0] DebugRegister,
    output DebugWriteReceived,
    output DebugSlaveSel,
    output DebugMOSI,
    output DebugSCLK,
    output [7:0] DebugIns
    );
    
    reg reset_p1;
    reg reset;
    always @(posedge clk)
    begin
        reset_p1 <= rst_;
        reset <= reset_p1;
    end
    //wire clk;
    //wire locked;
    
    SPI u_SPI(
        .MISO(MISO),
        .MOSI_Raw(MOSI_Raw),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .reset(reset),
        .SCLK_Raw(SCLK_Raw),
        .DebugRegister(DebugRegister),
        .DebugWriteReceived(DebugWriteReceived), 
        .DebugSlaveSel(DebugSlaveSel),      
        .DebugMOSI(DebugMOSI),          
        .DebugSCLK(DebugSCLK)           
        //For RAM
        //.Buffer_DataIn(),
        //.FIFO_OutRTR()
    );
    
    
endmodule
