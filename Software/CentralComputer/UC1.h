#pragma once
#include "Startknap.h"
#include "Display.h"
#include "SumoBot.h"
#include "Styringsenhed.h"

const int PLAYER_COUNT = 2;

using namespace std; 

struct Player {
	int direction;
	int speed;
	int life;
	bool attack; 
	SumoBot* SBptr;
	Styringsenhed* SEptr;
};

class UC1
{
public:
	UC1(Startknap* SK,Display *D,SumoBot *S1,SumoBot *S2,Styringsenhed *SE1, Styringsenhed *SE2);
	void run();
	~UC1();
private:
	Startknap* _SK; 
	Display* _D;
	Player _player[2];
};

