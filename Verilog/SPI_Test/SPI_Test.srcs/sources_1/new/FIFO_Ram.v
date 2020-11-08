`timescale 1ns / 1ps

module FIFO_Ram(
    input       FIFO_WEN,
    input [1:0] FIFO_InWADR,
    input [7:0] FIFO_InWDAT,
    input [1:0] FIFO_OutRADR,
    output [7:0] FIFO_OutRDAT,
    
    input       clk
    );
    
    reg [7:0] dataBuffer[1:0];
    
    assign FIFO_OutRDAT = dataBuffer[FIFO_OutRADR];
    
    always @(posedge clk)
    begin
        if (FIFO_WEN)
        begin
            dataBuffer[FIFO_InWADR] <= FIFO_InWDAT;
        end
    end
    
endmodule
