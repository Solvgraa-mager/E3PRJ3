#pragma once
#include "Communication.h"
#include <string>

class Wifi :
	public Communication
{
public:
	Wifi();
	int createHotspot(string SSID, string passphrase);
	int closeHotspot();
	int connectToWifi(string SSID, string passphrase, string MAC);
	int disconnectToWifi();
	virtual int sendMsg(string msg);
	virtual int receiveMsg(char *buffer, int length);
	~Wifi();
private:
	string SSID_;
	string passphrase_;
	string MAC_;
};

