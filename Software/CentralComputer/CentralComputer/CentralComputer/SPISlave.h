#pragma once
#include "SPI.h"

class SPISlave :
	public SPI
{
public:
	SPISlave(int channel, int speed);
	int send(string msg) override;
	int receive() override;
	~SPISlave();
};

