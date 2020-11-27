#include "Communication.h"

class I2C : 
	public Communication
{
public:
	I2C();
	int virtual send(string msg) = 0;
	int virtual receive() = 0;
	~I2C();
private:
	int SDA_Gipos;
	int SCL_Gpio;
	int clkFrequency;
};