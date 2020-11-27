#include "TCP.h"



TCP::TCP()
{

}

int TCP::send(string msg)
{
	cout << "TCP - Send: " << msg << endl;
	return 0;
}

int TCP::receive()
{
	cout << "TCP - recevied" << endl;
	return 0;
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
	return buffer;
}
TCP::~TCP()
{
}

	int getPort(); 
	void setPort();