#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include "Wifi.h"
#include "UC1.h"
#include <string.h>
#include <fstream>

int main(void)
{
	/*
	//Write to websocket instead of stdout 
	std::ofstream out("/www/pages/out.txt");
	std::cout.rdbuf(out.rdbuf());
	*/

	Startknap SK(12,16);
	Display D(20,4,1,1,1,1,1,1,1,1,1,1,1);
	D.writeToScreen("Press start..");
	SK.waitForStart();
	UC1 UC(&SK,&D);
	UC.run();
	return 0;
	
}