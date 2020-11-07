`timescale 1ns / 1ps

module tb();

    reg clk;
    reg SCLK;
    reg [1:0] SCLKCount;
    
    reg MISO;
    reg MOSI;
    reg SlaveSel;
    reg SlaveSelPre;

    
   
   reg [15:0] SPIWordArray [7:0];
   
   
   
   wire [15:0] SPIWord;
   wire [2:0] SPI_Cmd;
   wire [4:0] SPI_Params;
   wire [7:0] SPI_Data;
   
   reg [15:0] SPIWordIn;
   
   assign SPI_Cmd = SPIWord[15:13];
   assign SPI_Params = SPIWord[12:8];
   assign SPI_Data = SPIWord[7:0];
   
   
    reg [2:0] SixteenCountIn;
    reg [2:0] SixteenCountOut;
    reg [3:0] SixteenCount;
    reg [4:0] ThirtyTwoCount;
    always @(negedge SCLK)
    begin
        if(!SlaveSel)
        begin
            case (SPI_Cmd)
                3'b001:
                begin //32 bits- 16 to spi 16 out
                    if (SlaveSelPre)
                    begin
                        SlaveSel <= 1; //done //Slave Select is driven on posedge slk so need to move this to new process
                    end
                    else
                    begin
                        if (ThirtyTwoCount >= 16)
                        begin
                            if (ThirtyTwoCount == 31)
                            begin
                                SPIWordIn[SixteenCountOut] <= MISO; //DEBUG Will this work with slave sel going high here?
                                ThirtyTwoCount <= 0;
                                SixteenCountOut <= 0;
                                SixteenCountIn <= 0;
                                SlaveSelPre <= 1; //done- delay by 1
                            end
                            else
                            begin
                                SPIWordIn[SixteenCountOut] <= MISO;
                                SixteenCountOut <= SixteenCountOut + 1;
                                ThirtyTwoCount <= ThirtyTwoCount + 1;
                            end
                        end
                        else 
                        begin
                            MOSI <= SPIWord[SixteenCountIn];
                            SixteenCountIn <= SixteenCountIn + 1;
                            ThirtyTwoCount <= ThirtyTwoCount + 1;
                        end
                    end
                end
                3'b010: //16 bits
                begin
                    if (SlaveSelPre == 1)
                    begin
                        SlaveSel <= 1;
                    end
                    else
                    begin
                        if (SixteenCountIn == 15)
                        begin
                            MOSI <= SPIWord[SixteenCountIn];
                            SixteenCountIn <= 0;
                            SlaveSelPre <= 1;
                        end
                        else
                        begin
                            MOSI <= SPIWord[SixteenCountIn];
                            SixteenCountIn <= SixteenCountIn + 1;
                        end
                    end
                end
                3'b011: //8 bits
                begin
                end
            endcase
        end
    end
    
    
   initial 
   begin
      SPIWordArray[7] = 16'b0000000000000000;
      SPIWordArray[6] = 16'b0000000000000000;
      SPIWordArray[5] = 16'b0000000000000000;
      SPIWordArray[4] = 16'b0000000000000000;
      SPIWordArray[3] = 16'b0000000000000000;
      SPIWordArray[2] = 16'b0000000000000000;
      SPIWordArray[1] = 16'b0000000000000000;
      SPIWordArray[0] = 16'b0000000000000000;
   end
    
    initial
    begin
        clk = 0;
        SCLK = 0;
        SCLKCount = 0;
        MOSI = 0;
        SlaveSel = 1; 
        while (1)
            #5 clk = ~clk;  // toggle clk each 5 ns (100 MHz clock frequency)
    end
    
    always @(posedge clk) //Generate Slave Clock
    begin
        if (!SlaveSel)
        begin
            SCLKCount <= SCLKCount + 1;
            if (SCLKCount == 2'b01)
            begin
                #1 SCLK = ~SCLK;
            end
        end
    end
    
    reg SlaveCount;
    
    assign SPIWord = SPIWordArray[SlaveCount];
    initial begin
        #20 
        SlaveCount = 0;
        SlaveSel = 0;        
    end
    
    always @(posedge SCLK)
    begin
        if (SlaveSel)
        begin
            SlaveCount <= SlaveCount + 1;
        end
    end
    
    
    SPI u_SPI(
        .MISO(),
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .SCLK_Raw(SCLK), //DEBUG Generate Slave Clock???
        .Buffer_DataIn()
    );
    
endmodule
