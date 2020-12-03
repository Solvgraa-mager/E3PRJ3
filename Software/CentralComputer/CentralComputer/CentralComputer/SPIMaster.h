#pragma once
#include "SPI.h"
class SPIMaster :
	public SPI
{
public:
	SPIMaster(int channel, int speed);
	int send(string msg) override;
	int sendChar(char msg); 
	int receive() override;
	~SPIMaster();
private:
};

