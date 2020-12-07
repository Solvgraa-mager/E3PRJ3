
#include "TCP.h"
#include "Wifi.h"
#include "Communication.h"
#include "TCPServer.h"

int main(void)
{
	bool attack = true;

	TCPServer TCPS2;
	TCPS2.openServer(54002);


	while (true)
	{
		TCPS2.receiveMsg(); //wait for client to send data
		if (attack == true)
			TCPS2.sendMsg("ATTACK!"); //
		else
			TCPS2.sendMsg("No attack");
	}
		
	return 0;
}