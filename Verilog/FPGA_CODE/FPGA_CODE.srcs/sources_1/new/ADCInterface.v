`timescale 1ns / 1ps

module ADCInterface(
    input               ADC_XFC,
    input [9:0]         ADC_DataIn, 
    input               ADC_Sampleclock,
    input [1:0]         ADC_ShiftControl, //Right shift by 0, 1 or 2 bits, shifting 2 will make saturate useless, but keep it.
    //Shift before saturate- shift control determines how many bits to shift
    
    output reg [7:0]    Buffer_DataIn
    );
    //Data from ADC will be coming in as unsigned 
    reg signed [7:0] min = 8'h80; //-128
    reg signed [7:0] max = 8'h7F; //127;
    
    //Register for input range select
    //IRS (Input Range Select)
    //IRS = "VDDA" 2.0 VP-P differential input range
    //IRS = "VSSA" 1.5 VP-P differential input range IRS (Input Range 5 
    //IRS = "Floating" 1.0 VP-P differential input range 
    //Dont ever set IRS and IRG to 1 together
    
    
    //Saturate max and min, otherwise get 8 MSb from ADC_DataIn, if ADC is RTS
    always @(posedge ADC_Sampleclock)
    begin
        if (ADC_XFC)
        begin
            if (ADC_DataIn > max) 
            begin
                Buffer_DataIn <= max;
            end
            
            else if (ADC_DataIn < min)
            begin
                Buffer_DataIn <= min;
            end
            
            else
            begin
                Buffer_DataIn <= ADC_DataIn[9:1];
            end
        end
    end
    
endmodule
