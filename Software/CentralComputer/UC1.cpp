#include "UC1.h"
#include "Wifi.h"
#include "TCPServer.h"

UC1::UC1(Startknap* SK, Display* D)
{
	//Connect to wifi
	_W1 = new Wifi();
	_W1->createHotspot("SumoBot", "12345678");
	cout << "Hotspot made" << endl;
	
	_SK = SK; 
	_D = D; 

	//Define initial direction, speed, attack-status,SumoBot ptr and Styringsenheds ptr for UC1
	_player[0] = { 0,0,false,new SumoBot(3,1),new Styringsenhed(1,10000,1)};
	_player[1] = { 0,0,false,new SumoBot(3,2),new Styringsenhed(2,10000,3)};
	cout << "SumoBot og Syringsenhed constructed" << endl;
	_D->writeToScreen("Welcome to Robo Sumo Battle");
}

void UC1::run()
{
	_D->startCountDown(3);

	//While no players have 0 lives
	while((_player[0].SBptr->getLife() > 0) && (_player[1].SBptr->getLife()>0))
	{
		for (int i = 0; i < PLAYER_COUNT; i++)
		{
			cout << "For Player " << (i+1) << endl;
			//Retrieve dir and speed
			_player[i].SEptr->getDirectionAndSpeed(_player[i].direction, _player[i].speed);
			//Pass direction and speed to SumoBot 
			_player[i].attack = _player[i].SBptr->setDirectionAndSpeed(_player[i].direction, _player[i].speed);
			//If attack has happened
			if (_player[i].attack)
			{
				_player[0].SBptr->setDirectionAndSpeed(0,0);
				_player[1].SBptr->setDirectionAndSpeed(0,0);
				_player[i].SBptr->substractLife();
				_D->lostLife((i+1),_player[i].SBptr, _player[(i ? 0 : 1)].SBptr);
				_player[i].attack = false;
				break;
				_D->writeToScreen("Press start..");
				_SK->waitForStart();
				_D->startCountDown(3);
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
	delete _player[0].SBptr;
	delete _player[1].SBptr;
	delete _player[0].SEptr;
	delete _player[1].SEptr;
	delete _W1;
	_D->writeToScreen("Goodbye..");

}
