#pragma once
#include "SumoBot.h"
#include "I2CMaster.h"
#include <string>

using namespace std;

class Display
{
public:
	Display(int rows, int cols, int bits, int rs, int strb,
		int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7);
	void startCountDown(int count);
	void lostLife(int player, SumoBot *S1, SumoBot *S2);
	void showWinner(int winner);
	int  writeToScreen(string msg);
private:
	int _displayfd;
	int _rows;
	int _cols;
	int _bits;
	int _rs;
	int _strb;
	int _data[8];
};

