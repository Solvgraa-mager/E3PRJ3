#pragma once
#include "wiringPi/wiringPi.h"

class Startknap
{
public:
	Startknap(int gpio1, int gpio2);
	void waitForStart();
	~Startknap();
private:
	int _gpio[2];
	bool _status[2];
};

