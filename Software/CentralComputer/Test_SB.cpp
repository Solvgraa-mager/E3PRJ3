#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string.h>

int main(void)
{   
    int bufferLength = 8;
    char buffer[bufferLength];

    string SSID = "";
    string passphrase = "";
    string IPaddress = "";
    int playerNr = 1;
    string attackStatus = "1";

	CentralComputerIF C1(SSID, passphrase, IPaddress, playerNr);


    while(true)
    {
    C1.getDirSpeed(attackStatus, buffer, bufferLength);
    cout << buffer << endl; 
    }

	return 0;
}