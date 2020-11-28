`timescale 1ns / 1ps

module testbench();
    
    reg clk;
    reg reset;
    
    initial
    //Generate
    begin
        clk = 0;
        while(1)
        begin
            #5 clk = ~clk; //100MHZ clock. Board is capable of >450MHz
        end
    end
    
    initial
    //Initize reset
    begin
        reset = 1;
        #10 reset = 0;
    end
    
    /////////////////////
    //Initialize input Data
    `define numInputs     (16384)
    
    wire [9:0] stimInData;
    reg [13:0] stimInCount; //2^14 = 16384
    reg [9:0] stimData [`numInputs-1:0];
    
     assign stimInData = stimData[stimInCount];
    
    integer i;
    initial
    begin
        for (i = 0; i < `numInputs; i = i + 1)
        begin
            stimData[i] = $random();
        end
    end
    //End intialize data
    ///////////////////////////////////
    
    wire ADC_SampleClock; //Input from Timing Gen
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            stimInCount <= 0;
        end
    end
    
    always @(posedge ADC_SampleClock)
    //Inputs
        //Reset
    begin
        if (reset)
        begin
            stimInCount <= 0;
        end
        else
        begin
            stimInCount <= stimInCount + 1;
        end
    end
   // wire onBit;
  //  assign onBit = ~reset;
    
    ////////////////////////////////////////////////////////////
    //SPI TB
    
    reg SCLK;
    reg [1:0] SCLKCount;
    
    reg MISO;
    reg MOSI;
    reg SlaveSel;

    wire [15:0] command;
    reg [3:0] index;
    reg commandDone;
    reg [5:0] commandNum;
    reg [15:0] commandArray[4:0];
    initial
    begin
        commandNum <= 0;
        reset <= 1;
        SlaveSel <= 1;
        SCLK = 1;
        SCLKCount = 0;
        index = 15;
    end
    
    initial
    begin  
        commandArray[1] = 16'b0010010011111111; //cmd = Read, params = 4, data = x
        commandArray[0] = 16'b0100010011111111; //cmd = write, params = 4, data = 8'hFF
        commandArray[2] = 16'b0100010011110000; //cmd = write, params = 4, data = 8'hF0
        commandArray[3] = 16'b0010010011111111; //cmd = Read, params = 4, data = x
        commandArray[4] = 16'b0110010011111111; //cmd = Read Ram, params = 01111 -> (8 x 16 bits out), data = x... PARAMS = 00100 -> (1024 X 16 out)
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
        reset <= 0;
    end
    
    always @(posedge clk)
    begin
        if (commandDone)
        begin
            //#25
            SlaveSel <= 0;
        end
    end
    
    assign command = commandArray[commandNum];
    reg [6:0] OneTwentyEightCounter; //128
    reg [9:0] OneZeroTwoFourCounter; //1024

    always @(posedge SCLK)
    begin
        if (!SlaveSel)
        begin
            if (command[15:13] == 3'b011)
            begin
                MOSI <= command[index];
                if (index == 0)
                begin
                    if (OneZeroTwoFourCounter == 1023) //x TRANSFERS OF 16 BITS
                    begin
                        #40 
                        SlaveSel <= 1;
                        commandNum <= commandNum + 1;
                        commandDone <= 1;
                    end
                    else
                    begin
                        OneZeroTwoFourCounter <= OneZeroTwoFourCounter + 1;
                    end
                end
                else
                begin
                    index <= index - 1;
                end
            end
            else
            begin
                MOSI <= command[index];
                index <= index - 1;
                if (index == 0)
                begin
                    #40 
                    SlaveSel <= 1;
                    commandNum <= commandNum + 1;
                    commandDone <= 1;
                end
            end
        end
        else
        begin
            MOSI <= 0;
            index <= 15;
            OneTwentyEightCounter <= 0;
            OneZeroTwoFourCounter <= 0;
        end
    end
    
    Top u_Top(
        .clk(clk),
        .rst_(~reset),
        //SPI
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .SCLK_Raw(SCLK),
        //FIFO
  //      .onBit(onBit),
        .ADC_InData(stimInData),
        .ADC_SampleClock(ADC_SampleClock)
    );


    
    
    
endmodule
