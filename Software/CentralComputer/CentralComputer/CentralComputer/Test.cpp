#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string.h>

int main(void)
{
	SPIMaster S1;
	cout << "Object created" << endl;
	S1.send("123");
	cout << "Send returned" << endl;

	return 0;
}