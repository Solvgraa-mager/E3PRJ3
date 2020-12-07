#pragma once
class Styringsenhed
{
public:
	Styringsenhed(int channel, int speed, int bufferSize);
	int getDirectionAndSpeed(int& dir, int& speed);
	~Styringsenhed();
private:
	SPIMaster* _SPIM; 
	int _direction; 
	int _speed; 
};

