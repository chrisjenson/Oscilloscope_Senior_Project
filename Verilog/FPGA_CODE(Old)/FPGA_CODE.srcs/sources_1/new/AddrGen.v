module AddrGen(
    output reg [18:0]   RAMR_ReadAddr,
    output reg [18:0]   RAMW_WriteAddr,
    
    input               RAMW_WriteEn,
    
    input               Trigger_Triggered,
    
    input               clk,
    input               reset
);

    always @(posedge clk)
    begin
        if (reset)
        begin
            RAMR_ReadAddr <= 0;
            RAMW_WriteAddr <= 0;
        end
        else
        begin
            if (Trigger_Triggered)
            begin
                RAMR_ReadAddr <= RAMR_ReadAddr + 1;
            end
        
        
            //If read line, inc addr by 1
            //If wrote line, inc addr by 1
        end
    end

endmodule
