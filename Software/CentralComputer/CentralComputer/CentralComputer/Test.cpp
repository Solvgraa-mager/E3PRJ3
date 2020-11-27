#include "CentralComputerIF.h"
#include "TCPClient.h"

int main(void)
{
	cout << "Test" << endl; 
	TCPClient C1;
	CentralComputerIF CCIF(&C1);
	CCIF.getDirSpeed("1001");

	C1.createHotspot();
	return 0;
}