#include "SumoBot.h"
#include <cstdlib>

SumoBot::SumoBot(int lifes, int player)
{
	_lifes = lifes;
	_direction = 0; _speed = 0; 
	_attackStatus = false;

	//Create TCP-Server 
	_TCPS = new TCPServer();
	_TCPS->openServer(54000 + player); 

}

bool SumoBot::setDirectionAndSpeed(int dir, int speed)
{
	_direction = dir; 
	_speed = speed;
	string divider = "|";

	string msg = to_string(_direction)+divider+to_string(_speed);

	//Communication
	char attackStatusBuffer; 
	
	cout << "Sending speed: " << _speed << " and direction: " << _direction << endl; 
	if (_TCPS->sendMsg(msg.c_str()) < 0)
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
