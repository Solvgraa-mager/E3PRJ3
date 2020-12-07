
#include "TCP.h"
#include "Wifi.h"
#include "Communication.h"
#include "TCPServer.h"

int main(void)
{
	bool attack = false;
	TCPServer TCPS1;
	TCPS1.openServer(54001);

	while (true)
	{
		TCPS1.receiveMsg(); //wait for client to send data
		if (attack == true)
			TCPS1.sendMsg("ATTACK!"); 
		else
			TCPS1.sendMsg("No attack");
	}
	return 0;
}