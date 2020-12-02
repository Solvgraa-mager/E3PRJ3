#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include <string.h>

int main(void)
{
	cout << "Test" << endl; 
	//TCPClient C1("192.168.0.1", 54000);
	//C1.connectToServer();
	//CentralComputerIF CCIF(&C1);
	//CCIF.getDirSpeed("1001");
	//C1.createHotspot();
	TCPServer S(1);
	S.openServer();

	return 0;
}