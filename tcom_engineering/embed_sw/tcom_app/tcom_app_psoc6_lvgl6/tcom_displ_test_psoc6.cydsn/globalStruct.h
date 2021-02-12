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
    uint16_t RxBuffer[1024];  // Data Read in
    
    //Temp buffer
    uint16_t RegBuffer[13];

};
struct SPI_parameters cm4;

