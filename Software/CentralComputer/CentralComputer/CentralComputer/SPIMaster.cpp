#include "SPIMaster.h"
#include "wiringPiSPI.h"

#include <linux/types.h>

SPIMaster::SPIMaster(int channel, int speed)
	:SPI::SPI(channel,speed)
{
}

int SPIMaster::send(string msg)
{


	return 0;
}

int SPIMaster::sendChar(char msg)
{
	unsigned char buf[1] = {0};
	sscanf(msg,"%i", &buf);
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
