#include "SPISlave.h"

SPISlave::SPISlave(int channel, int speed, int bufferSize)
	:SPI(channel, speed, bufferSize)
{
}

int SPISlave::sendMsg(string msg)
{
	return 0;
}

int SPISlave::receiveMsg(char *buffer, int length)
{
	return 0;
}

SPISlave::~SPISlave()
{
}
