#include "UC1.h"

UC1::UC1(Startknap* SK, Display* D, SumoBot* SB1, SumoBot* SB2, Styringsenhed* SE1, Styringsenhed* SE2)
{
	_SK = SK; 
	_D = D; 
	_player[0].SBptr = SB1; 
	_player[1].SBptr = SB2;
	_player[0].SEptr = SE1;
	_player[1].SEptr = SE2;

	//Define initial direction, speed, attack-status,SumoBot ptr and Styringsenheds ptr for UC1
	_player[0] = { 0,0,3,false,_SB1,_SE1};
	_player[1] = { 0,0,3,false,_SB2,_SE2};

	_D->writeToScreen("Welcome to Robo Sumo Battle");
}

void UC1::run()
{

	_SK->waitForStart();
	_D->startCountDown(15);

	//While no players have 0 lives
	while(_player[0].SBptr->getLife() && _player[1].SBptr->getLife())
	{
		for (int i = 0; i < PLAYER_COUNT; i++)
		{
			//Retrieve dir and speed
			_player[i].SEptr->getDirectionAndSpeed(_player[i].direction, _player[i].speed);
			//Pass direction and speed to SumoBot 
			_player[i].attack = _player[i].SBptr->setDirectionAndSpeed(_player[i].direction, _player[i].speed);

			//If attack has happened
			if (_player[i].attack)
			{
				_player[i].SBptr->substractLife();
				_D->lostLife((i+1),_player[i].SBptr, _player[(i ? 0 : 1)].SBptr);
				_player[i].attack = false;
				_SK->waitForStart();
				_D->startCountDown(10);
			}
		}
	}
	//Pass loosing SumoBot to Display to show
	_D->showWinner(
		(!_player[0].SBptr->getLife() ? 1 :
		(!_player[1].SBptr->getLife() ? 2 : 0)) );
}

UC1::~UC1()
{
	_D->writeToScreen("Goodbye..");
}
