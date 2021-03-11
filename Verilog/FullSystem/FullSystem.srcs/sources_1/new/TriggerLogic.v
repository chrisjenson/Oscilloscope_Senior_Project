`timescale 1ns / 1ps

module TriggerLogic(
        input clk,
        input reset,
       // input ADC_SampleClock,
        input ADC_SampleClock_posedge_pulse,
        input onBit,
        
        input [7:0] TriggerType,
        input [7:0] TriggerThreshold,
        input [7:0] ADC_InData,

        output reg Triggered        
    );

    reg TriggerThreshold_p1;
    reg TriggerType_p1;
    
    wire getNewData;
    assign getNewData = ADC_SampleClock_posedge_pulse & onBit;
        
    reg [7:0] ADC_InData_p1;

    //assign triggered = 1;
    
    always @(posedge clk)
    //Gets delayed inputs
        //Inputs
            //Reset
            //RAMW_En
        //Outputs
            //ADC_InData_p1
            //TriggerType_p1
            //TriggerThreshold_p1
    begin
        if (reset)
        begin
            ADC_InData_p1 <= 0;
            TriggerType_p1 <= 0;
            TriggerThreshold_p1 <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin //New input
                ADC_InData_p1 <= ADC_InData;
            end
            
            TriggerType_p1 <= TriggerType;
            TriggerThreshold_p1 <= TriggerThreshold;
        end
    end
    
    always @(posedge clk)
    begin
    //Determines if trigger has happened
        //Inputs
            //Reset
            //RAMW_En
        //Outputs
            //triggered
        if (reset)
        begin
            Triggered <= 0;
        end
        else
        begin
            if ((TriggerType_p1 != TriggerType) || (TriggerThreshold_p1 != TriggerThreshold))
            begin
                Triggered <= 0;
            end
            else if (getNewData)
            begin
                if (TriggerType[1:0] == 0)
                begin 
                    //Rising
                    if (ADC_InData_p1 < ADC_InData)
                    begin
                        Triggered <= 1;
                    end
                end
                else if (TriggerType[1:0] == 1)
                begin
                    //Falling
                    if (ADC_InData_p1 > ADC_InData)
                    begin
                        Triggered <= 1;
                    end
//                    else
//                    begin
//                        triggered <= 0;
//                    end
                end
                else if (TriggerType[1:0] == 2)
                begin
                    //Threshold
                    if (TriggerType[2] == 0)
                    //above
                    begin
                        if (ADC_InData > TriggerThreshold)
                        begin
                            Triggered <= 1;
                        end
                    end
                    else
                    //below
                    begin
                        if (ADC_InData < TriggerThreshold)
                        begin
                            Triggered <= 1;
                       end
                    end
                    
                end
            end
        end
    end
    
    
endmodule
