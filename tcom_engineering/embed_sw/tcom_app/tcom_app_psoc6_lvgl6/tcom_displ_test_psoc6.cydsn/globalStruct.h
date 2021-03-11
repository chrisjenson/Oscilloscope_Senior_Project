#include "project.h"
#include "home_screen.h"

//Declaring a Global Structure
struct SPI_parameters
{
    uint8_t BrianReg;
    uint8_t ChrisReg;
    uint8_t ShannonReg;
    
    uint8_t VersionID;
    uint8_t Trigger;
    uint8_t TriggerSlope;
    uint8_t SampleRate;
    uint8_t onBit;
    uint8_t Reset;
    uint8_t IRS;
    uint8_t Offset;
    
    //uint16_t windowPos;
    int windowPos;
    int windowMin;
    int windowMax;    
    
    uint8_t HoriScale;
    uint8_t VertScale;
    uint8_t Gain;       //goes to Shannon
    
    //Actual Buffers
    uint16_t TxBuffer[13];  //Commands To be Sent
    uint16_t RxBuffer[8];  // Read data in, SIZE SHOULD BE EQUAL TO NUM_TO_WRITE in main_cm4.c
    uint8_t RamReadBuffer[1024];  // Ram Read data after being split can be 2048
    
    //Temp buffer
    uint16_t RegBuffer[13];

};
struct SPI_parameters cm4;

