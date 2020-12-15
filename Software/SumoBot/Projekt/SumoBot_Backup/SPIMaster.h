#pragma once
#include "SPI.h"
class SPIMaster :
	public SPI
{
public:
	SPIMaster(int channel, int speed, int bufferSize);
	int sendMsg(string msg) override;
	int sendChar(unsigned char msg); 
	int receiveMsg(char *buffer, int length) override;
	~SPIMaster();
private:

};

