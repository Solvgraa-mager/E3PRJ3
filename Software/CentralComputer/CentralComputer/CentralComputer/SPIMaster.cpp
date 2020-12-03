#include "SPIMaster.h"
#include "wiringPiSPI.h"
#include "string.h"

#include <linux/types.h>

SPIMaster::SPIMaster(int channel, int speed, int bufferSize)
	:SPI::SPI(channel,speed, bufferSize)
{
}

int SPIMaster::send(string msg)
{
	//Tjek om størrelsen af msg er lig med buffersize
	if((msg.length() + 1) != SPI::getBufferSize())
	{
		cout << "msg does not match wordlength"<<endl; 
		return -1; 
	}
	char buffer[SPI::getBufferSize()];
	strcpy(buffer,msg.c_str());
	wiringPiSPIDataRW(0,(unsigned char*)buffer,SPI::getBufferSize());
	return 0;
}

int SPIMaster::sendChar(unsigned char msg)
{
	unsigned char *buf = &msg;
	wiringPiSPIDataRW(0,buf,1);
	cout << "Send!" << endl;
	return 0;
}

int SPIMaster::receive(char *buffer, int length)
{
	unsigned char receieveBuffer[length]; 
	memset(receieveBuffer,0,length);
	wiringPiSPIDataRW(0,receieveBuffer,length);
	strcpy(buffer,(char*)receieveBuffer);
	cout << "Received: " << buffer << endl; 
	return 0;
}



SPIMaster::~SPIMaster()
{
}
