#include "SPIMaster.h"
#include "wiringPi/wiringPiSPI.h"
#include "string.h"

#include <linux/types.h>

SPIMaster::SPIMaster(int channel, int speed, int bufferSize)
	:SPI::SPI(channel,speed, bufferSize)
{
}

/// SendMsgStart
int SPIMaster::sendMsg(string msg)
{
	//Tjek om størrelsen af msg er lig med buffersize
	if((msg.length() + 1) != SPI::getBufferSize())
	{
		cout << "SPIMaster msg does not match wordlength"<<endl; 
		return -1; 
	}
	char buffer[SPI::getBufferSize()];
	strcpy(buffer,msg.c_str());
	if(wiringPiSPIDataRW(SPI::getChannel(),
				(unsigned char*)buffer,SPI::getBufferSize()) < 0)
	{
		cout << "SPIMaster: Could not send message" << endl; 
		return -2; 
	}
	
	return 0;
}
/// SendMsgStop

int SPIMaster::sendChar(unsigned char msg)
{
	unsigned char *buf = &msg;
	if (wiringPiSPIDataRW(SPI::getChannel(),buf,1)<0)
	{
		cout << "SPIMaster: Could not send byte" << endl; 
		return -1; 
	}
	return 0;
}
/// ReceiveMsgStart
int SPIMaster::receiveMsg(char *buffer, int length)
{
	int err = 0; 
	unsigned char receieveBuffer[length]; 
	memset(receieveBuffer,0,length);
	err = wiringPiSPIDataRW(SPI::getChannel(),receieveBuffer,length);
	if(err < 0)
	{
		cout << "SPIMaster: Could not receive data" << endl; 
		return -1; 
	}
	strcpy(buffer,(char*)receieveBuffer);
	cout << "Received: " << buffer << endl; 
	return 0;
}
/// ReceiveMsgStop


SPIMaster::~SPIMaster()
{
}
