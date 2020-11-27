#pragma once
#include "SPI.h"
class I2Slave :
	public SPI
{
public:
	SPISlave();
	int send() override;
	int receive() override;
private:
};

