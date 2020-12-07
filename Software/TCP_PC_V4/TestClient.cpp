
#include "TCP.h"
#include "Wifi.h"
#include "Communication.h"
#include "TCPClient.h"

int main(void)
{
	
	TCPClient TCPC1; //port 54001 viker :) 
	TCPC1.connectToServer("127.0.0.1", 54002);
	TCPC1.connectToServer("127.0.0.1", 54001);
	while (true)
	{
	TCPC1.sendMsg("0:Speed 10. Dir 50"); //sender til server 0, og aktivere
	TCPC1.receiveMsg();// modtager fra aktiveret server
	TCPC1.sendMsg("1:Speed 100. Dir 90"); //sender til server 1, og aktivere
	TCPC1.receiveMsg();//modtager fra aktiveret server.
	}
	return 0;
}