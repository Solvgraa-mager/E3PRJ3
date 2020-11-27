#pragma once
#include "SPI.h"
class SPISlave :
	public SPI
{
public:
	SPISlave();
	int send() override;
	int receive() override;
	~SPISlave()
};

