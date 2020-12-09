#pragma once
#include "SPIMaster.h"
class Styringsenhed
{
public:
	Styringsenhed(int channel, int Comspeed, int bufferSize);
	int getDirectionAndSpeed(int& dir, int& speed);
	~Styringsenhed();
private:
	SPIMaster* _SPIM; 
	int _direction; 
	int _speed; 
};

