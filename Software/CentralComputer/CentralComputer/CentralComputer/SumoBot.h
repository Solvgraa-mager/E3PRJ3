#pragma once
#include "Wifi.h"
#include "TCPServer.h"

class SumoBot
{
public:
	SumoBot(int lifes);
	bool setDirectionAndSpeed(int dir, int speed);
	int substractLife();
	int getLife();
	~SumoBot();
private:
	TCPServer* _TCPS;
	int _lifes;
	int _direction;
	int _speed; 
	bool _attackStatus;
};
