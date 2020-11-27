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

TCP::~TCP()
{
}
