#pragma once
class Styringsenhed
{
public:
	Styringsenhed();
	int getDirectionAndSpeed(int& dir, int& speed);
	~Styringsenhed();
private:
	int retning; 
	int speed; 
};

