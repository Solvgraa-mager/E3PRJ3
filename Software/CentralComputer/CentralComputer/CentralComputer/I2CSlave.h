#pragma once
#include "I2C.h"

class I2CSlave :
	public I2C
{
public:
	I2CSlave();
	int send(string msg) override;
	int receive() override;
	~I2CSlave();
private:
	int address;
};
