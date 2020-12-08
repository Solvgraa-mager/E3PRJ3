#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include "UC1.h"
#include <string.h>

int main(void)
{
	Startknap SK(12,16);
	SK.waitForStart();
	Display D(4,20,8,1,1,1,1,1,1,1,1,1,1);
	UC1 U(&SK,&D);
	U.run();

	return 0;
}