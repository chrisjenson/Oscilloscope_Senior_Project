`timescale 1ns / 1ps

module RAM_WriteEngine(
    input clk,
    input reset,
    input onBit, //Use this to gate everything
    input ADC_SampleClock,
    //Write
    output reg [17:0] RAMW_WriteAddr, //Port A on RAM
    input [17:0] TriggeredAddress,
    output RAMW_En,
    //For Ring Buffer
    input reading,
    input [17:0] RAMR_ReadAddr,

    //DEBUG
    output reg DebugRAMFullFlag
    );
    
    
    /////////////////////////////////////////////////
    //Get negedge and posedge pulses
    wire ADC_SampleClock_posedge_pulse;
    wire ADC_SampleClock_negedge_pulse;
    reg ADC_SampleClock_WaingForSecondPosedge;
    wire ADC_SampleClock_secondposedge_pulse;
    
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    always @(posedge clk)
    //Set signal
    begin
        if (reset)
        begin
            ADC_SampleClock_WaingForSecondPosedge <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin
                if (ADC_SampleClock_WaingForSecondPosedge)
                begin
                    ADC_SampleClock_WaingForSecondPosedge <= 0;
                end
                else
                begin
                    ADC_SampleClock_WaingForSecondPosedge <= 1;
                end
            end
        end
    end
    
    assign ADC_SampleClock_secondposedge_pulse = ADC_SampleClock_WaingForSecondPosedge & ADC_SampleClock_posedge_pulse;
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;
    assign ADC_SampleClock_negedge_pulse = ~ADC_SampleClock & ADC_SampleClock_p1;
    
    
    //End section
    //////////////////////////////////////////////////////////////   
    //RING BUFFER 
    reg ringBufferValid;

    always @(*) //DEBUG: always @* to fix the jumping issue on MCU?
    begin
    //Dont allow write addr to pass read addr 
    //Inputs
        //reset
        //RAMW_WriteAddr
        //RAMR_ReadAddr
    //Outputs
        //ringBufferValid
        if (reset)
        begin
            ringBufferValid = 0;
        end
        else
        begin
            if ((reading) && (RAMW_WriteAddr == RAMR_ReadAddr)) 
            begin //dont write
                ringBufferValid = 0;
            end
            else
            begin
                ringBufferValid = 1;
            end
        end
    end
    //////////////////////////////////////////////////////////////    
    //Write Section
    assign RAMW_En = onBit & ADC_SampleClock_secondposedge_pulse; //DEBUG:Need to make this its own process and delay by one word..
    
    always @(posedge clk)
    begin
    //Signal Ram to write
    //Inputs
        //Reset
        //RAMW_En
    //Outputs
        //RAMW_WriteAddr
        if (reset)
        begin
            RAMW_WriteAddr <= 0;
        end
        else
        begin
            if (RAMW_En && ringBufferValid) //Buffer_DataIn is set on negedge
            begin
                //if(RAMW_WriteAddr < 1024)//DEBUG REMOVE THIS IF
                //begin
                    RAMW_WriteAddr <= RAMW_WriteAddr + 1;
                //end 
                
            end
        end
    end
    
    always @(posedge clk)
    begin
    //Ram deubg output
    //Inputs
        //Reset
        //RAMW_En
    //Outputs
        //RAMW_WriteAddr
        if (reset)
        begin
            DebugRAMFullFlag <= 0;
        end
        else
        begin
            if (RAMW_WriteAddr >= 262143) //Buffer_DataIn in is set on negedge
            begin
                DebugRAMFullFlag <= 1;
            end
        end
    end

  
endmodule