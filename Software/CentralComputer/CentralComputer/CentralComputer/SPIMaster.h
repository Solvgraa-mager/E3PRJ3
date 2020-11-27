#pragma once
#include "SPI.h"
class SPIMaster :
	public SPI
{
public:
	SPIMaster();
	int send(string msg) override;
	int receive() override;
	~SPIMaster();
private:
};

