#include "UC1.h"

UC1::UC1(Startknap* SK, Display* D, SumoBot* SB1, SumoBot* SB2, Styringsenhed* SE1, Styringsenhed* SE2)
{
	_SK = SK; 
	_D = D; 
	_SB1 = SB1; 
	_SB2 = SB2; 
	_SE1 = SE1; 
	_SE2 = SE2; 

	_D->writeToScreen("Welcome to Robo Sumo Battle");
}

void UC1::run()
{
	int SB1_direction, SB2_direction,
		SB1_speed, SB2_speed;
	bool SB1_attack, SB2_attack;

	_SK->waitForStart();
	_D->startCountDown(15);
	//While no players have 0 lives
	while(_SB1->getLife() && _SB2->getLife())
	{
		/***				***/
		/***	SumoBot 1	***/
		/***				***/

		//Retrieve dir and speed
		_SE1->getDirectionAndSpeed(SB1_direction, SB1_speed);
		//Pass direction and speed to SumoBot 
		SB1_attack = _SB1->setDirectionAndSpeed(SB1_direction, SB1_speed);

		//If attack has happened
		if (SB1_attack)
		{
			_SB1->substractLife();
			_D->lostLife(_SB1, _SB2);
			_SK->waitForStart();
			_D->startCountDown(10);
		}
	}
	//Pass loosing SumoBot to Display to show
	_D->showWinner(
		(!_SB1->getLife() ? _SB1 :
		(!_SB2->getLife() ? _SB2 : 0)));
}

UC1::~UC1()
{
	_D->writeToScreen("Goodbye..");
}
