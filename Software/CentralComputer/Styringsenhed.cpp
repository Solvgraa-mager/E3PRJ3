#include "Styringsenhed.h"
#include "SPIMaster.h"

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

	if (_SPIM->receiveMsg(&receiveBuffer, 1) < 0)
	{
		cout << "STYRINGSENHED: Receive failed" << endl; 
		return -1; 
	}

	//Extract direction 
	dirBuffer = (receiveBuffer && 0b00000111);
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
		dir = 0; 
	//Convert right/left byte to +/-. + for right, - for left
	if (!((receiveBuffer && 0b00001000) >> 3))
		dir *= (-1);

	//Extract speed
	speedBuffer = ((receiveBuffer && 0b01110000) >> 4); 
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
	//Convert forward/backward byte to +/-. + for forward, - for backwards
	if (!((receiveBuffer && 0b10000000) >> 7))
		speed *= (-1);

	speed = _speed; 
	dir = _direction; 
	
	return 0;
}

Styringsenhed::~Styringsenhed()
{
	delete _SPIM;
}
