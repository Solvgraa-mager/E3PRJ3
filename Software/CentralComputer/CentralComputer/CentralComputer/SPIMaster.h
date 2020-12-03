#pragma once
#include "SPI.h"
class SPIMaster :
	public SPI
{
public:
	SPIMaster(int channel, int speed);
	int send(string msg) override;
	int sendChar(unsigned char msg); 
	int receive(char *buffer, int length) override;
	~SPIMaster();
private:
};

