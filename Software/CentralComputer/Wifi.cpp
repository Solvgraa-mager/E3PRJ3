#include "Wifi.h"
#include <unistd.h>
#include <stdlib.h>

Wifi::Wifi()
{
	SSID_ 		= "00000000"; 
	passphrase_ = "00000000";
	MAC_ 		= "00000000";
}
/// CreateHotspotStart
int Wifi::createHotspot(string SSID, string passphrase)
{
	SSID_ = SSID; //lager SSID. til f.esk nædlægning af HOTSPOT
	passphrase_ = passphrase; //lager password.

	int err = system(("echo SSID="+SSID_+">/etc/connman-hotspot.conf ; echo PASSWORD="+passphrase_+">>/etc/connman-hotspot.conf").c_str());
	if ((err == -1) || (err == 127)) 
		return -1;
	err = system("connman-hotspot enable");
	if ((err == -1) || (err == 127)) 
		return -2;

	return 0;
}
/// CreateHotspotStop
int Wifi::closeHotspot()
{
	
	int err = system("connman-hotspot disable");
	if ((err == -1) || (err == 127)) 
		return -1;
	
	return 0;
}


/// ConnectToWifiStart
int Wifi::connectToWifi(string SSID, string passphrase, string MAC)
{
	SSID_ = SSID; 				//Gemmer SSID
	passphrase_ = passphrase;	//Gemmer passphase
	MAC_ = MAC					//Gemmer MAC addresse

	int err = system("connmanctl scan wifi");
	if ((err == -1) || (err == 127)) 
		return -1;

	if (SSID == "SumoBot")//midlertidig løsning på SumoBot til Hex value.
	{	
		string SSID_hex = "53756d6f426f74"; //Text to Hex value. SumoBot = 53756d6f426f74
		err = system(("connmanctl connect wifi_"+MAC+"_"+SSID_hex+"_managed_psk").c_str()); //connman connect to hotspot
		if ((err == -1) || (err == 127)) 
		return -2;

		//passphrase here
		//if (pssphrase != true )
		//return -3;
	}
	else
	{
		return -4; //uknown SSID. midlertidlig løsning på convet text to Hex
	}
	
	return 0;
}
/// ConnectToWifiStop

int Wifi::disconnectToWifi()
{
	int err;
	
	if (SSID_ == "SumoBot")
	{
		string SumoBot_hex = "53756d6f426f74"; //Text to Hex value. SumoBot = 53756d6f426f74
		err = system(("connmanctl disconnect wifi_"+MAC_+SumoBot_hex"__managed_psk").c_str()); //connman connect to hotspot
		if ((err == -1) || (err == 127)) 
		return -2
	}
	else
	{
		return -1
	}
	
	return 0;
}	


Wifi::~Wifi()
{
	int err; 
	err = disconnectToWifi(SSID_);
	err = system("connman-hotspot disable");
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