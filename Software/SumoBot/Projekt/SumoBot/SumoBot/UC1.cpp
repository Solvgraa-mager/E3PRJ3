#include "UC1.h"

UC1::UC1(string SSID, string passphrase, string IPAddress, string MAC, int TCPClientPort)
{
	ASIF_ = new AttackSensorIF();
	CCIF_ = new CentralComputerIF(SSID, passphrase, IPAddress, MAC, TCPClientPort);
	MSIF_ = new MotorstyringIF();
}

UC1::~UC1()
{
	delete ASIF_;
	delete CCIF_;
	delete MSIF_;
}

void UC1::run()
{
    //Allocations  
    int receiverBufferLength = 8;
    char receiverBuffer[sizeof(receiverBufferLength)];  //Receiver buffer;
    memset(receiverBuffer, 0, receiverBufferLength); //fill receiverBuffer with 0;

    while (true)
    {
        /// <summary>
        /// Først checkes der om der har været et attack, som sendes med til CC gennem getDirSpeed.
        /// getDirSpeed returnerer en pointer til arrayet med hastighed & retning, som til sidst sendes med i setSpeedDir i MotorstyringIF.
        /// </summary>
        MSIF_->setSpeedDir(CCIF_->getDirSpeed((ASIF_->getAttackStatus() == true ? "1" : "0"), receiverBuffer, receiverBufferLength)); //byt til recievebuffer
    }
}
