#pragma once
#include "Communication.h"
#include "Wifi.h"
#include "TCP.h"
#include "TCPClient.h"

class CentralComputerIF
{
public:
	CentralComputerIF(string SSID, string passphrase, string IPAddress, int TCPClientPort);
	int getDirSpeed(string msg, char *buffer, int length);
	~CentralComputerIF();
private:
	TCPClient *_TCPC; 
	int _dir;
	int _speed;
	
};

