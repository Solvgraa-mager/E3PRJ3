#include "Startknap.h"

Startknap::Startknap(int gpio1, int gpio2)
{
	//Setup wiringPI and numbering of PIN's
	wiringPiSetup();

	_gpio[0] = gpio1;
	_gpio[1] = gpio2;

	//Choosen GPIO to be input
	pinMode(_gpio[0], 1);
	pinMode(_gpio[1], 1);
}

void Startknap::waitForStart()
{
	//Loop terminates when both players' status are 1 otherwise busy waiting for them
	while (!(_status[0] && _status[1]))
	{
		//Sets _status-array with 1's for ready player
		for (int i = 0; i < 2; i++)
			_status[i] = (digitalRead(_gpio[i]) ? 1 : _status[i]);
	}
}

Startknap::~Startknap()
{
	//GPIOs not needs to be free'd
}
