#include "Wifi.h"
#include <unistd.h>
#include <stdlib.h>

Wifi::Wifi()
{
	SSID_ = "00000000"; 
	passphrase_ = "00000000";
}

int Wifi::createHotspot(string SSID, string passphrase)
{
	int err;
	SSID_ = SSID; //lager SSID. til f.esk nædlægning af HOTSPOT
	passphrase_ = passphrase; //lager password.

	err = system(("echo SSID="+SSID+">/etc/connman-hotspot.conf ; echo PASSWORD="+passphrase+">>/etc/connman-hotspot.conf").c_str());
	if ((err == -1) || (err == 127)) 
		return -1;
	err = system("connman-hotspot enable");
	if ((err == -1) || (err == 127)) 
		return -2;

	return 0;
}

int Wifi::closeHotspot()
{
	
	int err = system("connman-hotspot disable");
	if ((err == -1) || (err == 127)) 
		return -1;
	
	return 0;
}



int Wifi::connectToWifi(string SSID, string passphrase)
{
	 SSID_ = SSID;

	int err = system("connmanctl scan wifi");

	if ((err == -1) || (err == 127)) 
		return -1;

	if (SSID == "SumoBot") 
	{
		string CC_AP_name = "wifi_b827eb5189ef_53756d6f426f74_managed_psk"; //ikke rigtig AP navn for CC
		err = system(("connmanctl connect " + CC_AP_name).c_str());
		if ((err == -1) || (err == 127)) 
		return -2;

		//passphrase here
		//if (pssphrase != true )
		//return -3;
	}
	else
	{
		return -4;
	}
	
	return 0;
}

int Wifi::disconnectToWifi(string SSID)
{
	int err;
	
	if (SSID == "CC") 
	{
		string CC_AP_name = "wifi_b827eb5189ef_53756d6f426f74_managed_psk"; //ikke rigtig AP navn for CC
		err = system(("connmanctl disconnect " + CC_AP_name).c_str());
		if ((err == -1) || (err == 127)) 
			return -1;
	}
	else
	{
		return -2;
	}
	
	return 0;
}	


Wifi::~Wifi()
{
	int err; 
	err = disconnectToWifi(SSID_);
	if (err == -1) 
		cout << "WIFI DESTRUCTOR DISCONNECT ERROR: " << err;

	err = system("connman-hotspot disable");
	if ((err == -1) || (err == 127)) 
		cout << "WIFI DESTRUCTOR SYSTEM COMMAND ERRO: "	 << err;

	
}

int Wifi::sendMsg(string msg)
{
	cout << "Need at communicatione method. f.eks. TCP" << endl;
	return 0; 
}

int Wifi::receiveMsg(char *buffer, int length)
{
	cout << "Need at communicatione method. f.eks. TCP" << endl;
	return 0; 
}