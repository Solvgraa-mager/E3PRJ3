#include "SPI.h"
#include "wiringPiSPI.h"


SPI::SPI(int channel, int speed)
{
    _fd = wiringPiSPISetup(0, 10000);
}

int SPI::getfd()
{
    return _fd; 
}

SPI::~SPI()
{
}
