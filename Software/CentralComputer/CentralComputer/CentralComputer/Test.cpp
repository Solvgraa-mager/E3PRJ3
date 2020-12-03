#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string.h>

int main(void)
{
	SPIMaster S1(0,10000,4);
	cout << "Object created" << endl;
	while(1){
	S1.send("123");
	cout << "Send returned" << endl;
	char receiveBuffer[8*4]; 
	S1.receive(receiveBuffer,4);
	cout << receiveBuffer << endl; 
	usleep(500000);
	}
	return 0;
}