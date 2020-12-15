#pragma once
#include <dos.h> //delay function
#include "AttackSensorIF.h"
#include "CentralComputerIF.h"
#include "MotorstyringIF.h"

class UC1
{
public:
	UC1(string SSID, string passphrase, string IPAddress, string MAC, int TCPClientPort);
	~UC1();
	void run();
private:
	AttackSensorIF *ASIF_; //Skaber forbindelse til klassen AttacksensorIF
	CentralComputerIF *CCIF_; //Skaber forbindelse til klassen CentralComputerIF
	MotorstyringIF *MSIF_; //Skaber forbindelse til klassen MotorstyringIF
};

