#include "SumoBot.h"
#include <cstdlib>

SumoBot::SumoBot(int lifes, int player)
{
	_lifes = lifes;
	_direction = 0; _speed = 0; 
	_attackStatus = false;
/// SumoBotCreateTCPServerStart
	//Create TCP-Server 
	_TCPS = new TCPServer();
	_TCPS->openServer(54000 + player);
	cout << "SumoBot player " << player << " connected!" << endl;
/// SumoBotCreateTCPServerStop

}

bool SumoBot::setDirectionAndSpeed(int dir, int speed)
{
/// SumoBotSetDirectionAndSpeedStart
	_direction = dir; 
	_speed = speed;
	string divider = "|";

	string msg = to_string(_direction)+divider+to_string(_speed);

	//Communication
	char attackStatusBuffer[2];
	
	cout << "Sending speed: " << _speed << " and direction: " << _direction << endl; 
	if (_TCPS->sendMsg(msg.c_str()) < 0)
	{
		cout << "SUMOBOT: Send failed!" << endl; 
		return -1; 
	}
	if (_TCPS->receiveMsg(attackStatusBuffer, 2) < 0)
	{
		cout << "SUMOBOT: Receive failed!" << endl; 
		return -2;
	}

	//Retrieve false/true from asci '0'/'1'
	_attackStatus = attackStatusBuffer[0] - '0';

	return (_attackStatus ? true : false);
/// SumoBotSetDirectionAndSpeedStop
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
