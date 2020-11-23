`timescale 1ns / 1ps

module RAM_WriteEngine(
    input clk,
    input reset,
    input onBit, //Use this to gate everything
    input ADC_SampleClock,
    //Write
    input [7:0] Buffer_DataIn,
    output reg [18:0] RAMW_WriteAddr, //Port A on RAM
    output [7:0] RAMW_Data
    );
    
    
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
    //////////////////////////////////////////////////////////////    
    //Write Section
    reg writeFlag;
    
//    always @(posedge clk)
//    begin
//    //Write data to RAMW_Data for input into ram, contigent on flag
//    //Inputs
//        //Reset
//    //Outputs
//        //writeFlag
//        //RAMW_WriteAddr
//        if (reset)
//        begin
//        end
//        else
//        begin
//            if (ADC_SampleClock_negedge_pulse) //Buffer_DataIn in is set on negedge
//            begin
//                writeFlag <= 1;
//                RAMW_Data <= Buffer_DataIn;
//            end
//        end
//    end
    wire RAMW_En;
    assign RAMW_En = onBit & ADC_SampleClock_posedge_pulse;
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