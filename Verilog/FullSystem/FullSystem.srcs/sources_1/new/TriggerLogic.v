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

        output reg triggered        
    );
    
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
    begin
        if (reset)
        begin
            ADC_InData_p1 <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin //New input
                ADC_InData_p1 <= ADC_InData;
            end
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
            //Reset
        end
        else
        begin
            if (getNewData)
            begin
                //DEBUG: TRIGGERED MUST STAY HIGH EVEN IF GOES BELOW VALUE AGAIN
                if (TriggerType[1:0] == 0)
                begin 
                    //Rising
                    if (ADC_InData_p1 < ADC_InData)
                    begin
                        triggered <= 1;
                    end
//                    else
//                    begin
//                        triggered <= 0;
//                    end
                end
                else if (TriggerType[1:0] == 1)
                begin
                    //Falling
                    if (ADC_InData_p1 > ADC_InData)
                    begin
                        triggered <= 1;
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
                        if (ADC_InData > {TriggerThreshold, 2'b00})
                        begin
                            triggered <= 1;
                        end
                    end
                    else
                    //below
                    begin
                        if (ADC_InData < {TriggerThreshold, 2'b00})
                        begin
                            triggered <= 1;
                       end
                    end
                    
                end
                else
                begin
                    
                end
            end
        end
    end
    
    
endmodule
