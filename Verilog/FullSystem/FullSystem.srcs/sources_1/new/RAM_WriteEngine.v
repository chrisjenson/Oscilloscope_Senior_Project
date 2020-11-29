`timescale 1ns / 1ps

module RAM_WriteEngine(
    input clk,
    input reset,
    input onBit, //Use this to gate everything
    input ADC_SampleClock,
    //Write
    input [15:0] Buffer_DataIn,
    output reg [17:0] RAMW_WriteAddr, //Port A on RAM
    output [15:0] RAMW_Data,
    output RAMW_En
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
    //////////////////////////////////////////////////////////////    
    //Write Section
    assign RAMW_En = onBit & ADC_SampleClock_secondposedge_pulse; //DEBUG:Need to make this its own process and delay by one word..
    // in order to prevent invalid data in the first
    assign RAMW_Data = Buffer_DataIn;
    
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
            if (RAMW_En) //Buffer_DataIn in is set on negedge
            begin
                RAMW_WriteAddr <= RAMW_WriteAddr + 1;
            end
        end
    end

  
endmodule