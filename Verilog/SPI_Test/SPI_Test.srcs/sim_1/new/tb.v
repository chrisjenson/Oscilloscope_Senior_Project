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
    
    //reg MISO;
    reg MOSI;
    reg SlaveSel;

    initial
    begin
        clk = 0;
        SCLK = 0;
        SCLKCount = 0;
        MOSI = 0;
        SlaveSel =1;
        while (1)
            #5 clk = ~clk;  // toggle clk each 5 ns (100 MHz clock frequency)
    end
    
    always @(posedge clk)
    begin
        SCLKCount <= SCLKCount + 1;
        if (SCLKCount == 2'b01)
        begin
            SCLK = ~SCLK;
        end
    end
   
    reg [15:0] SPIWord;
    reg [3:0] MOSICount;
    always @(posedge SCLK)
    begin
        if(!SlaveSel)
        begin
            MOSI <= SPIWord[MOSICount];
            MOSICount <= MOSICount + 1;
        end
        else
        begin
            MOSICount <=0;
        end
    end
    
    integer SlaveCount = 0;
    initial begin
        //SPIWord = 16'b0100000111111111; //0100000111111111 
        #20 
        SlaveSel = 0;
        SPIWord = 16'b0100000111111111;
        
    end
    
    
    
    
    SPI u_SPI(
        .MISO(),
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .SCLK_Raw(SCLK) //DEBUG Generate Slave Clock???
    );
    
endmodule
