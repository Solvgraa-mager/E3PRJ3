#include "Styringsenhed.h"
#include "SPIMaster.h"
#include <bitset>


Styringsenhed::Styringsenhed(int channel, int Comspeed, int bufferSize)
{
	_direction = 0; _speed = 0; 
	_SPIM = new SPIMaster(channel, Comspeed, bufferSize); 
}

int Styringsenhed::getDirectionAndSpeed(int& dir, int& speed)
{
	char receiveBuffer = 0; 
	char dirBuffer = 0; 
	char speedBuffer = 0; 
	
	//Receive message via SPI class
	if (_SPIM->receiveMsg(&receiveBuffer, 1) < 0)
	{
		cout << "STYRINGSENHED: Receive failed" << endl; 
		return -1; 
	}

	//Extract direction 
	dirBuffer = (receiveBuffer & 0b00000111);
	if (dirBuffer == 0b111)
		_direction = 90;
	else if (dirBuffer == 0b110)
		_direction = 68;
	else if (dirBuffer == 0b101)
		_direction = 56;
	else if (dirBuffer == 0b100)
		_direction = 45;
	else if (dirBuffer == 0b011)
		_direction = 34;
	else if (dirBuffer == 0b010)
		_direction = 23;
	else if (dirBuffer = 0b001)
		_direction = 11;
	else
		_direction = 0; 

	//Convert right/left-byte to +/-.
	//bit 3 = 1 for right (positive angle), bit 3 = 1 for left (negative angle)
	if (!(receiveBuffer & (1 << 3)))
		_direction *= (-1);

/// StyringsenhedExtractSpeedStart
	//Extract speed
	speedBuffer = ((receiveBuffer & 0b01110000) >> 4); 
	if (speedBuffer == 0b111)
		_speed = 100;
	else if (speedBuffer == 0b110)
		_speed = 88;
	else if (speedBuffer == 0b101)
		_speed = 75;
	else if (speedBuffer == 0b100)
		_speed = 63;
	else if (speedBuffer == 0b011)
		_speed = 50;
	else if (speedBuffer == 0b010)
		_speed = 38;
	else if (speedBuffer == 0b001)
		_speed = 25;
	else
		_speed = 0; 
	//Convert forward/backward byte to +/-.
	//bit 7 = 1 for forward (positive speed), bit 7 = 0 for backwards (negative speed)
	if (!(receiveBuffer & (1 << 7)))
		_speed *= (-1);
/// StyringsenhedExtractSpeedStop

	cout << "Received speed: " << _speed << " and Direction: "<< _direction << endl;
 	speed = _speed; 
	dir = _direction; 
	
	return 0;
}

Styringsenhed::~Styringsenhed()
{
	delete _SPIM;
}
