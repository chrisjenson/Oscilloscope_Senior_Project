`timescale 1ns / 1ps


module RAM_ReadEngine(
    input clk,
    input reset,
    //input ADC_SampleClock,
    //Ram Read
    input triggered,
    input SPI_ReadCommand,
    output reg [17:0] RAMR_ReadAddr, //Port B on RAM, current read location
    input [17:0] RAMR_Quantity,
    input SlaveSel,
    //input [15:0] RAMR_Data,
    //FIFO
    //output reg [15:0] RAMData,
    output DEBUGreading,
    
    output reg FIFO_InRTS,
    input FIFO_InRTR
    );
    
    wire FIFO_InXFC;
    assign FIFO_InXFC = FIFO_InRTS & FIFO_InRTR;
    //DEBUG Need to implement a Ring buffer
    wire reading; //DEBUG READING IS LOW 11/30/2020
    assign reading = (RAMR_ReadAddr < RAMR_Quantity) & SPI_ReadCommand & triggered;
    
    always @(posedge clk)
    begin
    //Determing if RAM should be reading data
    //Inputs
        //Reset
        //reading
        //FIFO_InXFC
    //Outputs
        //RAMR_ReadAddr
        //FIFO_InRTS
        if (reset)
        begin
            RAMR_ReadAddr <= 0;
            FIFO_InRTS <= 0;
        end
        else
        begin
            if (SlaveSel)
            //If SPI is done reading
            begin
                RAMR_ReadAddr <= 0; //If not reading, address is 0;
            end
            if (reading)
            begin
                FIFO_InRTS <= 1;
                if (FIFO_InXFC)
                begin
                    RAMR_ReadAddr <= RAMR_ReadAddr + 1;
                end
            end
            else
            begin
                FIFO_InRTS <= 0;
            end
        end
    end
    
    
   
endmodule
