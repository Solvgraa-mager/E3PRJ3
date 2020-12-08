
#include "CentralComputerIF.h"

CentralComputerIF::CentralComputerIF(string SSID, string passphrase, string IPAddress, int playerNr)
{
	cout << "CentralComputerIF constructor called" << endl;

	_TCPC = new TCPClient();
	_TCPC->connectToWifi("SSID", "passphrase");
	_TCPC->connectToServer(IPAddress, playerNr+54000);
}

int CentralComputerIF::getDirSpeed(string msg, char *buffer, int length)
{
	_TCPC->receiveMsg(buffer, length);
	cout << "GetDirSpeed() called" << endl; 

	//******************
	_dir = 99; 
	_speed = 99; 
	//forstår ikke hvorfor dir_speed modtages i binært. 
	//konverterginen tilbage til binært i Sumobot?
	//Så skal de konveretes tilbage til dir,speed som int igen her
	//Synes vi skal sende de atributter der fåes ved Styringsenheden.
	//*********************

	cout << "Sending Attack status Back" << msg << endl; 
	_TCPC->sendMsg(msg);
	return 0;
}

CentralComputerIF::~CentralComputerIF()
{
	delete _TCPC;
}
