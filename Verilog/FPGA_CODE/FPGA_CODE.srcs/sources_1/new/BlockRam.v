`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/19/2020 06:49:29 PM
// Design Name: 
// Module Name: BlockRam
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


module BlockRam(
    input [7:0] writeData, readData,
	input [18:0] writeAddr, readAddr,
	input writeEn, clk, reset
	//output reg [7:0] q_a, q_b
    );
    
    // Declare the RAM variable
	reg [7:0] Bram[259999:0];
	
    reg [18:0] writePTR;
    reg writePTRIncrement;
    
	assign writeAddr = writePTR;
	// WRITE
	always @ (posedge clk)
	begin
	   //RESET
        if (reset)
        begin
           writePTR <= 0;
        end
        //INCREMENT WRITE PTR
        if (writePTRIncrement)
        begin
            writePTR <= writePTR + 8;
        end
        //WRITE DATA
		if (writeEn) 
		begin
		    writePTRIncrement <= 1;
			Bram[writeAddr] <= writeData;
            
			//q_a <= data_a;
		end
	end
	
	// READ
	always @ (posedge clk)
	begin
		
	end
    
endmodule
