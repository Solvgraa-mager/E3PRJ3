#include "Communication.h"

class I2C : 
	public Communication
{
public:
	I2C();
	int sendMsg(string msg);
	int receiveMsg();
	~I2C();
private:
	int SDA_Gipos;
	int SCL_Gpio;
	int clkFrequency;
};