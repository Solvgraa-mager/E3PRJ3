#include "SPIMaster.h"
#include "wiringPiSPI.h"
#include "string.h"

#include <linux/types.h>

SPIMaster::SPIMaster(int channel, int speed)
	:SPI::SPI(channel,speed)
{
}

int SPIMaster::send(string msg)
{
	int n = msg.length();
	char buffer[n];
	strcpy(buffer,msg.c_str());
	wiringPiSPIDataRW(0,(unsigned char*)buffer,sizeof(buffer));
	return 0;
}

int SPIMaster::sendChar(unsigned char msg)
{
	unsigned char *buf = &msg;
	wiringPiSPIDataRW(0,buf,1);
	cout << "Send!" << endl;
	return 0;
}

int SPIMaster::receive()
{
	return 0;
}



SPIMaster::~SPIMaster()
{
}
