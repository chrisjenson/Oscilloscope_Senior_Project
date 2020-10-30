`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/29/2020 11:47:22 PM
// Design Name: 
// Module Name: tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb();
    
    reg clk;
    reg SCLK;
    reg [1:0] SCLKCount;
    
    initial
    begin
        clk = 0;
        SCLKCount = 0;
        while (1)
            #5 clk = ~clk;  // toggle clk each 5 ns (100 MHz clock frequency)
    end
    
    always @(posedge clk)
    begin
        SCLKCount <= SCLKCount + 1;
        if (SCLKCount == 2'b11)
        begin
            SCLK = ~SCLK;
        end
    end
    
endmodule
