#include "SPISlave.h"

SPISlave::SPISlave(int channel, int speed)
	:SPI(channel, speed)
{
}

int SPISlave::send(string msg)
{
	return 0;
}

int SPISlave::receive()
{
	return 0;
}

SPISlave::~SPISlave()
{
}
