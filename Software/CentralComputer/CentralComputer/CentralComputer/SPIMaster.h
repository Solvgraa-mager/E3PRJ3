#pragma once
#include "SPI.h"
class SPIMaster :
	public SPI
{
public:
	SPIMaster();
	int send() override;
	int receive() override;
	~SPIMaster();
private:
};

