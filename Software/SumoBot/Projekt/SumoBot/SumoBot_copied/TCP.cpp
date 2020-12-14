#include "TCP.h"

TCP::TCP()
{
	buffer_size_ = MAX_BUFFER_SIZE;
	port_ = 0;		
}

int TCP::getPort()
{
	return port_;
}

void TCP::setPort(int port)
{
	port_ = port;
}

char* TCP::getBuffer()
{
	return buffer_;
}

TCP::~TCP()
{
		
}
