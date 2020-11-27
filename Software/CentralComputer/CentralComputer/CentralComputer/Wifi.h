#pragma once
#include "Communication.h"

class Wifi :
	public Communication
{
public:
	Wifi();
	int createHotspot();
	int connectToWifi();
	~Wifi();
private:
	string SSID;
	string passphrase;
};

