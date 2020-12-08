#pragma once
#include "Startknap.h"
#include "Display.h"
#include "SumoBot.h"
#include "Styringsenhed.h"
#include "Wifi.h"

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
	UC1(Startknap* SK, Display* D);
	void run();
	~UC1();
private:
	Startknap* _SK; 
	Display* _D;
	Player _player[2];
	Wifi* _W1;
};

