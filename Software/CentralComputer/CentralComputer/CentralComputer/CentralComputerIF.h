#pragma once
#include "Communication.h"

class CentralComputerIF
{
public:
	CentralComputerIF(Communication *com_ptr);
	int getDirSpeed(string msg);
	~CentralComputerIF();
private:
	int dir; 
	int speed; 
	Communication *com; 
};

