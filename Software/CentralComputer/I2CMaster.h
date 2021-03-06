#pragma once
#include "I2C.h"

class I2CMaster :
	public I2C
{
public:
	I2CMaster();
	int sendMsg(string msg) override;
	int receiveMsg(char *buffer, int length) override;
	~I2CMaster();
private:
	int address[MAX_CLIENT_COUNT];
	int clientCount;
};

