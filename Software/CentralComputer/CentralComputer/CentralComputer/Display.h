#pragma once
#include <string>

using namespace std;

class Display
{
public:
	Display();
	void startCountDown(int count);
	void lostLife(&sumoBot S1, &sumoBot S2);
	void showWinner(&sumoBot S);
private:
	void writeToScreen(string msg);
};

