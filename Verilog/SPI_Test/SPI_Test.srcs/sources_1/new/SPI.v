`timescale 1ns / 1ps

module SPI(
        output reg MISO,
        input MOSI,
        input SlaveSel,
        input clk,
        input SCLK //DEBUG Generate Slave Clock???
    );
    
    reg Reg_WrEn;
    reg Reg_RdEn;
    
    reg [3:0] SPI_OutSixteenCount;
    reg [3:0] SPI_InSixteenCount;
    
    reg [2:0] SPI_Cmd;
    reg [4:0] SPI_Params;
    reg [7:0] SPI_Data;
    
    reg [15:0] SPIWord;
    reg [15:0] SPI_DataIn;
    assign SPI_Cmd = SPIWord[15:13];
    assign SPI_Params = SPIWord[12:8];
    assign SPI_Data = SPIWord[7:0];
    
    reg [7:0] Reg_DataOut;
    reg [7:0] Reg_DataIn;
     
    always @(*)
    begin
        case (SPI_Cmd)
            3'b000: //ReadReg- MISO //DEBUG THIS MAY CAUSE ISSUES SINCE DEFAULT IS 000
            begin
                Reg_RdEn = 1;
                Reg_WrEn = 0;
            end
            3'b001: //Write- MOSI
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 1;
            end
            3'b010: //ReadData- MISO
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 0;
            end
        endcase
    end
    always @(posedge clk)
    begin
        if (SlaveSel) //Do not read on high
        begin
            SPI_InSixteenCount <= 0;
            SPI_OutSixteenCount <= 0;
            SPI_DataIn <= 16'h0000;
            SPIWord <= 16'h0000; //DEBUG This will trigger cmd=000
            
            Reg_RdEn <= 0;//DEBUG should these go here?
            Reg_WrEn <= 0;
        end
    end
    always @(posedge SCLK)//DEBUG okay to use SCLK???
    begin
        if (!SlaveSel)
        begin
            //Read 1 bit at a time
            if (!Reg_RdEn)
            begin
                SPI_DataIn[SPI_InSixteenCount] <= MOSI;
                if (SPI_InSixteenCount == 4'hF)
                begin
                    SPIWord <= SPI_DataIn;
                end
                
                SPI_InSixteenCount <= SPI_InSixteenCount + 1;
            end
           
            if (Reg_RdEn)
            begin
                MISO <= Reg_DataOut[SPI_OutSixteenCount];
                if (SPI_OutSixteenCount == 4'hF)
                begin
                    
                end
                SPI_OutSixteenCount <= SPI_OutSixteenCount +1;
            end
        end
    end
     
    Regs(
        .Write_Data(Reg_DataIn),
        .Write_Addr(SPI_Params),
        .WrEn(Reg_WrEn),
        .RdEn(Reg_RdEn),
        .Read_Addr(SPI_Params),
        .Read_Data(Reg_DataOut)
    );
endmodule
