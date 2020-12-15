
#include "CentralComputerIF.h"

CentralComputerIF::CentralComputerIF(string SSID, string passphrase, string IPAddress, string MAC, int playerNr)
{
	_TCPC = new TCPClient(); //create TCPClient
	_TCPC->connectToWifi(SSID, passphrase, MAC);
	_TCPC->connectToServer(IPAddress, playerNr+54000);
}

int CentralComputerIF::getDirSpeed(string msg, char *buffer, int length)
{
	_TCPC->receiveMsg(buffer, length);
	cout << "Receive: dir|speed: " << buffer << endl; 
	_TCPC->sendMsg(msg);
	cout << "Send: Attack status: " << msg << endl; 
	return 0;
}

CentralComputerIF::~CentralComputerIF()
{
	delete _TCPC;
}
