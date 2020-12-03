#include "SPI.h"
#include "wiringPiSPI.h"


SPI::SPI(int channel, int speed, int bufferSize)
{
    _fd = wiringPiSPISetup(0, 10000);
    _buffer_size = bufferSize; 
}
int SPI::getBufferSize(){
    return _buffer_size;
}
void SPI::setBufferSize(int bufferSize){
    _buffer_size = bufferSize;
}
int SPI::getclkFreq(){
    return _clkFrequency;
}
void SPI::setClkFreq(int clkFreq){
    _clkFrequency = clkFreq;
}

int SPI::getfd()
{
    return _fd; 
}

SPI::~SPI()
{
}
