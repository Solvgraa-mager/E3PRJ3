#include "SPISlave.h"

SPISlave::SPISlave(int channel, int speed, int bufferSize)
	:SPI(channel, speed, bufferSize)
{
}

int SPISlave::send(string msg)
{
	return 0;
}

int SPISlave::receive(char *buffer, int length)
{
	return 0;
}

SPISlave::~SPISlave()
{
}
