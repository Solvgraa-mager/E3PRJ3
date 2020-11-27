
#include "CentralComputerIF.h"

CentralComputerIF::CentralComputerIF(Communication *com_ptr)
{
	com = com_ptr;
}

int CentralComputerIF::getDirSpeed(string msg)
{
	cout << "GetDirSpeed() called" << endl; 
	cout << "Sending " << msg << endl; 
	com->send(msg);
	return 0;
}

CentralComputerIF::~CentralComputerIF()
{
}
