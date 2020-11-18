`timescale 1ns / 1ps

module tb();

    reg clk;
    reg rst;
    reg SCLK;
    reg [1:0] SCLKCount;
    
    reg MISO;
    reg MOSI;
    reg SlaveSel;
    ////////////////////////////////////////////
    
 
 ///////////////////////////////////////////////////////////////////////////////////
    wire [15:0] command;
    reg [3:0] index;
    reg commandDone;
    reg [5:0] commandNum;
    reg [15:0] commandArray[1:0];
    initial
    begin
        commandNum <= 0;
        rst <= 1;
        SlaveSel <= 1;
        clk = 0;
        SCLK = 0;
        SCLKCount = 0;
        index = 15;
        while (1)
            #5 clk = ~clk;  // toggle clk each 5 ns (100 MHz clock frequency)
    end
    
    initial
    begin  
        commandArray[0] = 16'b0100010011111111; //cmd = write, params = 4, data = 8'hFF
        commandArray[1] = 16'b0010010011111111; //cmd = Read, params = 4, data = x
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
    initial 
    begin
        #210
        SlaveSel <=0;
        rst <= 0;
    end
    
    always @(posedge clk)
    begin
        if (commandDone)
        begin
            #200
            SlaveSel <= 0;
        end
    end
    
    assign command = commandArray[commandNum];
    
    always @(posedge SCLK)
    begin
        if (!SlaveSel)
        begin
            MOSI <= command[index];
            index <= index - 1;
            if (index == 0)
            begin
                SlaveSel <= 1;
                commandNum <= commandNum + 1;
                commandDone <= 1;
            end
        end
        else
        begin
            MOSI <= 0;
            index <= 15;
        end
    end
    
    SPI u_SPI(
        .reset(rst),
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .SCLK_Raw(SCLK), 
        .Buffer_DataIn()
    );
    /////////////////////////////////////////////////////////
    /*
    //reg SlaveSelPre;
    reg SPITransferDone;

    
   
   reg [15:0] SPIWordArray [7:0];
   
   
   
   wire [15:0] SPIWord;
   wire [2:0] SPI_Cmd;
   wire [4:0] SPI_Params;
   wire [7:0] SPI_Data;
   
   reg [15:0] SPIWordIn;
   
   assign SPI_Cmd = SPIWord[15:13];
   assign SPI_Params = SPIWord[12:8];
   assign SPI_Data = SPIWord[7:0];
   
   
    reg [3:0] SixteenCountIn;
    reg [3:0] SixteenCountOut;
    reg [3:0] SixteenCount;
    reg [4:0] ThirtyTwoCount;
    always @(negedge SCLK)
    begin
        if(!SlaveSel)
        begin
                case (SPI_Cmd)
                    3'b001:
                    begin //32 bits- 16 to spi 16 out
                        
                        if (ThirtyTwoCount >= 16)
                        begin
                            if (ThirtyTwoCount == 31)
                            begin
                                SPIWordIn[SixteenCountOut] <= MISO; //DEBUG Will this work with slave sel going high here?
                                ThirtyTwoCount <= 0;
                                SixteenCountOut <= 0;
                                SixteenCountIn <= 0;
                                SPITransferDone <= 1; //done
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
                    3'b010: //16 bits
                    begin
                        if (SixteenCountIn == 15)
                        begin
                            MOSI <= SPIWord[SixteenCountIn];
                            SixteenCountIn <= 0;
                            SPITransferDone <= 1;
                        end
                        else
                        begin
                            MOSI <= SPIWord[SixteenCountIn];
                            SixteenCountIn <= SixteenCountIn + 1;
                        end
                    end
                    3'b011: //8 bits
                    begin
                    end
                    default:
                    begin
                        if (SixteenCountIn == 15)
                        begin
                            MOSI <= SPIWord[SixteenCountIn];
                            SixteenCountIn <= 0;
                            SPITransferDone <= 1;
                        end
                        else
                        begin
                            MOSI <= SPIWord[SixteenCountIn];
                            SixteenCountIn <= SixteenCountIn + 1;
                        end
                    end
                endcase
            end
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
    
    reg [3:0] SlaveCount;
    
    assign SPIWord = SPIWordArray[SlaveCount];
    
    always @(posedge SCLK)
    begin
        if (SPITransferDone)
        begin
            //SlaveSel <= 0;
            //SPITransferDone <= 0;
        end
    end
    always @(negedge SCLK)
    begin
        if (SPITransferDone)
        begin
            SPITransferDone <= 0;
            SlaveCount <= SlaveCount + 1;
            //SlaveSel <= 1;
            
            //SlaveCount <= 0;
        end
    end
    
    initial 
    begin
       SPIWordArray[0] = 16'b0010000000000000;
       SPIWordArray[1] = 16'b0010000000000000;
       SPIWordArray[2] = 16'b0100000000000000;
       SPIWordArray[3] = 16'b0110000000000000;
       SPIWordArray[4] = 16'b1000000000000000;
       SPIWordArray[5] = 16'b1010000000000000;
       SPIWordArray[6] = 16'b1100000000000000;
       SPIWordArray[7] = 16'b1110000000000000;
    end
    
    initial
    begin
        #20
        SlaveCount <= 0;
        SlaveSel <=0;
        
    end
    
    initial
    begin
        SixteenCountIn = 0;
        SixteenCountOut = 0;
        SixteenCount = 0;  
        ThirtyTwoCount = 0;
        SPITransferDone = 0;
        clk = 0;
        SCLK = 0;
        SCLKCount = 0;
        SlaveCount = 0;
        MOSI = 0;
        SlaveSel = 1; 
        while (1)
             #5 clk = ~clk;  // toggle clk each 5 ns (100 MHz clock frequency)
    end
    
        SPI u_SPI(
        .MISO(),
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .SCLK_Raw(SCLK), //DEBUG Generate Slave Clock???
        .Buffer_DataIn()
    );
 */
    
endmodule
