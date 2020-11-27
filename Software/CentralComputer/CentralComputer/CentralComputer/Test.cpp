#include "CentralComputerIF.h"
#include "TCPClient.h"

int main(void)
{
	cout << "Test" << endl; 
	TCPClient C1("192.168.0.1", 54000);
	CentralComputerIF CCIF(&C1);
	CCIF.getDirSpeed("1001");

	C1.createHotspot();
	return 0;
}