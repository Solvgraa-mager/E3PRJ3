#pragma once
#include "SumoBot.h"
#include "I2CMaster.h"
#include <string>

using namespace std;

class Display
{
public:
	Display();
	void startCountDown(int count);
	void lostLife(SumoBot *S1, SumoBot *S2);
	void showWinner(SumoBot *S);
	void writeToScreen(string msg);
private:
};

