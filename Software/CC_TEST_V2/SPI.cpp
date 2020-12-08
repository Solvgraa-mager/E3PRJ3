#include "SPI.h"
#include "wiringPi/wiringPiSPI.h"


SPI::SPI(int channel, int speed, int bufferSize)
{
    _fd = wiringPiSPISetup(channel, 10000);
    _buffer_size = bufferSize; 
    _channel = channel; 
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
int SPI::getChannel(){
    return _channel;
}

int SPI::getfd()
{
    return _fd; 
}

SPI::~SPI()
{
}
