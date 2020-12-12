
#include "CentralComputerIF.h"

CentralComputerIF::CentralComputerIF(string SSID, string passphrase, string IPAddress, int playerNr)
{
	_TCPC = new TCPClient(); //create TCPClient
	_TCPC->connectToWifi(SSID, passphrase);
	_TCPC->connectToServer(IPAddress, playerNr+54000);
}

int CentralComputerIF::getDirSpeed(string attackstatus, char *buffer, int length)
{
	int err = _TCPC->receiveMsg(buffer, length); 
	if (err == -1)
		return -1 
	cout << "Receive: dir|speed: " << buffer << endl;

	err = _TCPC->sendMsg(msg);
	if (err == -1)
		return -2 
	cout << "Send: Attack status: " << attackstatus << endl; 
	
	return 0;
}

CentralComputerIF::~CentralComputerIF()
{
	delete _TCPC;
}
