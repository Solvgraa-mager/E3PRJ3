#include "Styringsenhed.h"
#include "SPIMaster.h"

Styringsenhed::Styringsenhed(int channel, int speed, int bufferSize)
{
	_direction = 0; _speed = 0; 
	_SPIM = new SPIMaster(channel, speed, bufferSize); 
}

int Styringsenhed::getDirectionAndSpeed(int& dir, int& speed)
{

	return 0;
}

Styringsenhed::~Styringsenhed()
{
	delete _SPIM;
}
