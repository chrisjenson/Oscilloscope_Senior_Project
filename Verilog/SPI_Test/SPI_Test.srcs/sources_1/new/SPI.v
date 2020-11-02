`timescale 1ns / 1ps

module SPI(
        output reg MISO,
        input MOSI_Raw,
        input SlaveSel,
        input clk,
        input SCLK_Raw
    );
    
    reg Reg_WrEn;
    reg Reg_RdEn;
    
    reg [3:0] SPI_OutSixteenCount;
    reg [3:0] SPI_InSixteenCount;
    
    reg [2:0] SPI_Cmd;
    reg [4:0] SPI_Params;
    reg [7:0] SPI_Data;
    
    reg [15:0] SPIWord; //spiword is valid on the last possckposedgepulse of the word
    reg [15:0] SPI_DataIn;
    assign SPI_Cmd = SPIWord[15:13];
    assign SPI_Params = SPIWord[12:8];
    assign SPI_Data = SPIWord[7:0];
        
    reg [7:0] Reg_DataOut;
    reg [7:0] Reg_DataIn;
    
    reg sck;
    reg sck_p1;
    reg sck_raw_p1;
    reg MOSI_raw_p1;
    reg MOSI;
    reg sck_posedge_pulse;
    reg sck_negedge_pulse;
    
    
    reg new_word_strobe;
     
    always @(*)
    begin
        case (SPI_Cmd)
            3'b001: //ReadReg- MISO //DEBUG 000 MAY CAUSE ISSUES SINCE DEFAULT IS 000
            begin
                Reg_RdEn = 1;
                Reg_WrEn = 0;
            end
            3'b010: //Write- MOSI
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 1;
            end
            3'b011: //ReadData- MISO RAM Read
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 0;
            end
        endcase
    end
    
    always @(posedge clk)
    begin
        sck_p1 <= sck; 
    end
    
    always @(posedge clk) //Avoid metastability for digital input
    begin 
        sck_raw_p1 <= SCLK_Raw;
        sck <= sck_raw_p1;
        
        MOSI_raw_p1 <= MOSI_Raw;
        MOSI <= MOSI_raw_p1; //one cycle delay
    end
    
    assign sck_posedge_pulse = sck & ~sck_p1;
    assign sck_negedge_pulse = ~sck & sck_p1;
    
    always @(posedge clk) //Read from reg
    begin
        new_word_strobe <= 0;
        if (SlaveSel) //Do not read on high/ SPI done transferring word
        begin
            SPI_InSixteenCount <= 4'hF;
            SPI_OutSixteenCount <= 4'hF;
            SPI_DataIn <= 16'h0000;
            SPIWord <= 16'h0000;

            Reg_RdEn <= 0;//DEBUG should these go here?
            Reg_WrEn <= 0;
            
        end
        else
        begin
            if (sck_posedge_pulse)
            begin
                if (!SlaveSel)
                begin
                    //Read 1 bit at a time
                    if (!Reg_RdEn)
                    begin
                        SPI_DataIn[SPI_InSixteenCount] <= MOSI;
                        if (SPI_InSixteenCount == 4'h0)
                        begin
                            new_word_strobe <= 1;
                            SPIWord <= {SPI_DataIn[15:1], MOSI}; //Valid word including 0th bit
                        end
                        
                        SPI_InSixteenCount <= SPI_InSixteenCount - 1;
                    end
                end
            end
            //Drive on negedge and sample on pos edge so need opposite of negative edge here
            if (sck_negedge_pulse)
            begin
                if (Reg_RdEn)
                begin
                    if (SPI_OutSixteenCount > 7)
                    begin
                        MISO <= 0;
                    end
                    else
                    begin
                        MISO <= Reg_DataOut[SPI_OutSixteenCount];
                        if (SPI_OutSixteenCount == 4'h0) //MSB first and not LSB
                        begin
                            Reg_RdEn <= 0;
                        end
                    end
                    SPI_OutSixteenCount <= SPI_OutSixteenCount - 1;
                end
            end
        end
    end
    
    
     
    Regs u_REGS(
        .Write_Data(SPI_Data),
        .Regs_Addr(SPI_Params),
        .WrEn(Reg_WrEn & new_word_strobe),
        .RdEn(Reg_RdEn),
        .Read_Data(Reg_DataOut)
    );
endmodule
