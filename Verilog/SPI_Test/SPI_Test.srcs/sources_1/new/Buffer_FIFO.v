`timescale 1ns / 1ps

module Buffer_FIFO(
    input FIFO_OutRTR,
    output FIFO_OutRTS,
    
    input FIFO_InRTS,
    output FIFO_InRTR,
    
    input [15:0]FIFO_InData,
    output [15:0]FIFO_OutData,
    
    output FIFO_OutXFC,
    
    input clk,
    input reset
    );
    
    wire FIFO_InXFC;
    
    reg [1:0] FIFO_NumInFIFO;
    reg [1:0] FIFO_WPTR;
    reg [1:0] FIFO_RPTR;
    
    assign FIFO_OutXFC = FIFO_OutRTR & FIFO_OutRTS;
    assign FIFO_InXFC = FIFO_InRTS & FIFO_InRTR;
    
    assign FIFO_OutRTS = (0 < FIFO_NumInFIFO) && (!reset);
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            FIFO_WPTR <= 0;
            FIFO_RPTR <= 0;
            FIFO_NumInFIFO <= 0;
        end
        else
        begin
            if (FIFO_OutXFC) //Reading data
            begin
                FIFO_RPTR <= FIFO_RPTR + 1;
            end
            if (FIFO_InXFC) //Write data
            begin
                FIFO_WPTR <= FIFO_WPTR + 1;
            end
        end
        if (FIFO_InXFC != FIFO_OutXFC)
        begin
            if (FIFO_InXFC)
            begin
                FIFO_NumInFIFO <= FIFO_NumInFIFO + 1;
            end
            if (FIFO_OutXFC)
            begin
                FIFO_NumInFIFO <= FIFO_NumInFIFO - 1;
            end
        end
    end
    
    FIFO_Ram u_FIFO_Ram
    (
        .FIFO_WEN(FIFO_InXFC),     
        .FIFO_InWADR(FIFO_WPTR),  
        .FIFO_InWDAT(FIFO_InData),  
        .FIFO_OutRADR(FIFO_RPTR), 
        .FIFO_OutRDAT(FIFO_OutData),
                  
        .clk(clk)           
    );
    
    
endmodule
