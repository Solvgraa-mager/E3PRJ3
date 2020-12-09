#pragma once
#include "SPI.h"

class SPISlave :
	public SPI
{
public:
	SPISlave(int channel, int speed, int bufferSize);
	int sendMsg(string msg) override;
	int receiveMsg(char *buffer, int length) override;
	~SPISlave();
};

