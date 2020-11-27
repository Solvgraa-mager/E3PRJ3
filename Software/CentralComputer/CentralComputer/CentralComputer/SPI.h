#pragma once
#include "Communication.h"
class SPI :
	public Communication
{
public:
	SPI();
	~SPI()
private:
	int MOSI_GPIO;
	int MISO_GPIO;
	int clk_GPIO;
	int SS_GPIO; 
	int buffer_Size;
};

