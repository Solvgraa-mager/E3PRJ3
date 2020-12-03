#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string.h>

int main(void)
{
	SPIMaster S1(0,10000);
	cout << "Object created" << endl;
	while(1){
	S1.send("1234567890");
	cout << "Send returned" << endl;
	}
	return 0;
}