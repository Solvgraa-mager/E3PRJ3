#include "SumoBot.h"
#include <cstdlib>

SumoBot::SumoBot(int lifes, int TCPServerPort)
{
	_lifes = lifes;
	_direction = 0; _speed = 0; 
	_attackStatus = false;

	//Create TCP-Server 
	_TCPS = new TCPServer();
	_TCPS->openServer(TCPServerPort); //Sleeping till 1 connected client 

}

bool SumoBot::setDirectionAndSpeed(int dir, int speed)
{
	_direction = dir; 
	_speed = speed;

	string msg[8] = {0};

	//Parce dir and speed
	msg[7] = (_speed < 0 ? '0' : '1');
	//Speed intervals is average between each step according to protocol
	if (abs(_speed) > 100 && abs(_speed) < 94)
	{
		msg[6] = '1'; msg[5] = '1'; msg[4] = '1';
	}
	else if (abs(_speed) < 94 && abs(_speed) > 81)
	{
		msg[6] = '1'; msg[5] = '1'; msg[4] = '0';
	}
	else if (abs(_speed) < 81 && abs(_speed) > 69)
	{
		msg[6] = '1'; msg[5] = '0'; msg[4] = '1';
	}
	else if (abs(_speed) < 69 && abs(_speed) > 56)
	{
		msg[6] = '1'; msg[5] = '0'; msg[4] = '0';
	}
	else if (abs(_speed) < 56 && abs(_speed) > 44)
	{
		msg[6] = '0'; msg[5] = '1'; msg[4] = '1';
	}
	else if (abs(_speed) < 44 && abs(_speed) > 31)
	{
		msg[6] = '0'; msg[5] = '1'; msg[4] = '0';
	}
	else if (abs(_speed) < 31 && abs(_speed) > 13)
	{
		msg[6] = '0'; msg[5] = '0'; msg[4] = '1';
	}
	else
	{
		msg[6] = '0'; msg[5] = '0'; msg[4] = '0';
	}

	//Direction Right or left. Right = 1, Left = 0
	msg[7] = (_direction < 0 ? '0' : '1');

	//Direction according to protocol
	if (abs(_direction) > 90 && abs(_direction) < 79)
	{
		msg[2] = '1'; msg[1] = '1'; msg[0] = '1';
	}
	else if (abs(_direction) < 79 && abs(_direction) > 62)
	{
		msg[2] = '1'; msg[1] = '1'; msg[0] = '0';
	}
	else if (abs(_direction) < 62 && abs(_direction) > 51)
	{
		msg[2] = '1'; msg[1] = '0'; msg[0] = '1';
	}
	else if (abs(_direction) < 51 && abs(_direction) > 39)
	{
		msg[2] = '1'; msg[1] = '0'; msg[0] = '0';
	}
	else if (abs(_direction) < 39 && abs(_direction) > 28)
	{
		msg[2] = '0'; msg[1] = '1'; msg[0] = '1';
	}
	else if (abs(_direction) < 28 && abs(_direction) > 17)
	{
		msg[2] = '0'; msg[1] = '1'; msg[0] = '0';
	}
	else if (abs(_direction) < 17 && abs(_direction) > 6)
	{
		msg[2] = '0'; msg[1] = '0'; msg[0] = '1';
	}
	else
	{
		msg[2] = '0'; msg[1] = '0'; msg[0] = '0';
	}

	//Communication
	char attackStatusBuffer; 
	
	cout << "Sending speed: " << _speed << " and direction: " << _direction << endl; 
	if (_TCPS->sendMsg(msg->c_str()) < 0)
	{
		cout << "SUMOBOT: Send failed!" << endl; 
		return -1; 
	}
	if (_TCPS->receiveMsg(&attackStatusBuffer, 1) < 0)
	{
		cout << "SUMOBOT: Receive failed!" << endl; 
		return -2;
	}

	_attackStatus = attackStatusBuffer - '0';

	return _attackStatus;
}

int SumoBot::substractLife()
{
	_lifes--;
	_attackStatus = false; 
	return _lifes;
}

int SumoBot::getLife()
{
	return _lifes;
}

SumoBot::~SumoBot()
{
	delete _TCPS;
}
