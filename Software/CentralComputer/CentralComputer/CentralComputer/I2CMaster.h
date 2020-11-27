#pragma once

#include "I2C.h"

class I2CMaster :
	public I2C
{
	I2CMaster();
	int send() override;
	int receive() override;
	~I2CMaster();
};

