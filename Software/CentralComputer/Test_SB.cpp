#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string.h>

int main(void)
{   
    string buffer;
	CentralComputerIF C1("SSID", "passshrase", "192.168.0.1", 54001);
    C1.getDirSpeed()


	return 0;
}