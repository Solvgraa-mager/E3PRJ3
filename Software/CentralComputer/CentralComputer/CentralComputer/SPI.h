#pragma once
#include "Communication.h"
class SPI :
	public Communication
{
public:
	SPI(int channel, int speed);
	void setSpiParameters();
	int getfd();
	~SPI();
private:
	int _fd;
	int _MOSI_GPIO;
	int _MISO_GPIO;
	int _clk_GPIO;
	int _SS_GPIO; 
	int _buffer_size;
	int _clkFrequency;
};

