#pragma once
#include "Communication.h"
class SPI :
	public Communication
{
public:
	SPI(int channel, int speed, int bufferSize);
	int getBufferSize();
	void setBufferSize(int bufferSize);
	int getclkFreq();
	void setClkFreq(int clkFreq);
	int getChannel();
	int getfd();
	~SPI();
private:
	int _fd;
	int _buffer_size;
	int _clkFrequency;
	int _channel; 
};

