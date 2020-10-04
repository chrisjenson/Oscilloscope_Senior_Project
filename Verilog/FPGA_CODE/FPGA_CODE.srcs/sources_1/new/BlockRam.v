`timescale 1ns / 1ps


module ram_model_1w1r
#( parameter
    WORDLENGTH = 32,
    LOG2_DEPTH =  2
)
(
    input      [LOG2_DEPTH-1:0] IN_WADR,
    input                       IN_WEN,
    input      [WORDLENGTH-1:0] IN_WDAT,
    
    input      [LOG2_DEPTH-1:0] OUT_RADR,
    output     [WORDLENGTH-1:0] OUT_RDAT,
    
    input                       clk
);

reg [WORDLENGTH-1:0]        dbuf[(1<<LOG2_DEPTH)-1:0];    // storage array

assign OUT_RDAT = dbuf[OUT_RADR];      // retrieve read data

// num_in_buf
always @ (posedge clk)
begin
    if (IN_WEN)
        dbuf[IN_WADR]   <= IN_WDAT;             // store write data
end

/*
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
*/