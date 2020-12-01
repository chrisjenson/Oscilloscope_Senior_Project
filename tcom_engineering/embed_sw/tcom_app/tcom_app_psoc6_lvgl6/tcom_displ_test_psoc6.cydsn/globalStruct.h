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
    uint8_t HoriSCale;
    uint8_t VertScale;
    uint8_t Gain;       //goes to Shannon
    
    uint16_t RegBuffer[13];

};
struct SPI_parameters cm4;

