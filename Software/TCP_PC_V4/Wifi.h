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
	int connectToWifi(string SSID, string passphrase);
	int disconnectToWifi(string SSID);
	~Wifi();
private:
	string SSID_;
	string passphrase_;
};

