#include "UC1.h"

UC1::UC1(string SSID, string passphrase, string IPAddress, string MAC, int TCPClientPort)
{
	ASIF_ = new AttackSensorIF();
	//CCIF_ = new CentralComputerIF(SSID, passphrase, IPAddress, MAC, TCPClientPort);
	MSIF_ = new MotorstyringIF();
}

UC1::~UC1()
{
	delete ASIF_;
	//delete CCIF_;
	delete MSIF_;
}

void UC1::run()
{
    //Allocations  
 // int receiverBufferLength = 8;
 // char receiverBuffer[sizeof(receiverBufferLength)];  //Receiver buffer;
 // memset(receiverBuffer, 0, receiverBufferLength); //fill receiverBuffer with 0;

    char sekvens1[] = { '-','3','7','|','0','\0' };
    char sekvens2[] = { '4','4','|','5','0','\0' };
    char sekvens3[] = { '-','7','5','|','-','9','0','\0' };
    char sekvens4[] = { '3','0','|','0','\0' };
    char sekvens5[] = { '5','0','|','9','0','\0' };
    char sekvens6[] = { '-','7','7','|','-','5','5','\0' };

    while (true)
    {
         //CCIF_->getDirSpeed((ASIF_->getAttackStatus() == true ? "1" : "0"), receiverBuffer, receiverBufferLength); //Send attackStatus, Receive dir|speed.

        MSIF_->setSpeedDir(sekvens1); //byt til recievebuffer
        delay(1000);
        MSIF_->setSpeedDir(sekvens2);
        delay(1000);
        MSIF_->setSpeedDir(sekvens3);
        delay(1000);
        MSIF_->setSpeedDir(sekvens4);
        delay(1000);
        MSIF_->setSpeedDir(sekvens5);
        delay(1000);
        MSIF_->setSpeedDir(sekvens6);
        delay(1000);
    }
}
