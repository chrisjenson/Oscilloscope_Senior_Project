`timescale 1ns / 1ps


module Ram_ReadEngine(
    input clk,
    input reset,
    input ADC_SampleClock,
    //Ram Read
    input triggered,
    input SPI_ReadCommand,
    output reg [18:0] RAMR_ReadAddr, //Port B on RAM, current read location
    input [18:0] RAMR_Quantity,
    input [7:0] RAMR_Data,
    //FIFO
    output reg [15:0] ConcatRAMData,
    output reg FIFO_InRTS,
    input FIFO_InRTR
    );
    wire FIFO_InXFC;
    assign FIFO_InXFC = FIFO_InRTS & FIFO_InRTR;
    //DEBUG Need to implement a Ring buffer
    /////////////////////////////////////////////////
    //Get negedge and posedge pulses
    wire ADC_SampleClock_posedge_pulse;
    wire ADC_SampleClock_negedge_pulse;
    
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;
    assign ADC_SampleClock_negedge_pulse = ~ADC_SampleClock & ADC_SampleClock_p1;
    //End section
    //////////////////////////////////////////////////////////////  
    //Read conditions met?
    reg reading;

    always @(posedge clk)
    begin
    //Set ram read engine to reading mode
    //Inputs
        //Reset
        //triggered
        //RAMR_ReadAddr
        //RAMR_Quantity
    //Outputs
        //reading
        if (reset)
        begin
            reading <= 0;
        end
        else
        begin
            if (SPI_ReadCommand)
            begin
                if (triggered)
                begin
                    if (RAMR_ReadAddr >= RAMR_Quantity)
                    begin
                        reading <= 0;
                        //DEBUG RESET HERE, TRIGGER TO 0?
                    end
                    else
                    begin
                        reading <= 1;
                    end
                end
            end
        end
    end
    
    //////////////////////////////////////////////////////////////  
    //Concat Ram data from to 15:0 and drive rts
    reg twoCounter;
    always @(posedge clk)
    begin
    //Signal Read Ram
    //Inputs
        //Reset
        //reading
        //RAMR_Data
    //Outputs
        //ConcatRamData
        //FIFO_InRTS - Data ready for FIFO
        if (reset)
        begin
            ConcatRAMData <= 0;
            twoCounter <= 0;
            FIFO_InRTS <= 0;
        end
        else
        begin
            if (reading) //If in reading mode
            begin
                if (!FIFO_InRTS)
                begin
                    if (twoCounter == 1)
                    begin
                        ConcatRAMData[7:0] <= RAMR_Data;
                        FIFO_InRTS <= 1;
                    end
                    else
                    begin
                        ConcatRAMData[15:8] <= RAMR_Data;
                        twoCounter <= twoCounter + 1;
                    end  
                end
                if (FIFO_InXFC)
                begin
                    twoCounter <= 0;
                    FIFO_InRTS <= 0;
                end
            end
            else
            begin
                ConcatRAMData <= 0;
                twoCounter <= 0;
                FIFO_InRTS <= 0;
            end
        end
    end
      
    //////////////////////////////////////////////////////////////    
    //Ram Read
    wire [7:0] readdata;
    assign readdata = RAMR_Data;
    
    always @(posedge clk)
    begin
    //Signal Read Ram
    //Inputs
        //Reset
        //triggered
    //Outputs
        //RAMR_ReadAddr
        if (reset)
        begin
            RAMR_ReadAddr <= 0;
        end
        else
        begin
            if (reading) //If triggered and recieved command
            begin
                if (!FIFO_InRTS)
                begin
                    //If data to send it is built but not sent
                    RAMR_ReadAddr <= RAMR_ReadAddr + 1;
                end
                else
                begin
                    //RAMR_ReadAddr <= RAMR_ReadAddr + 1;
                end
            end
            else
            begin
                RAMR_ReadAddr <= 0;
            end
        end
    end
    
    /////////////////////////////////////////
    //
    
endmodule
