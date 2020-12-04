#pragma once
#include "Startknap.h"
#include "Display.h"
#include "SumoBot.h"
#include "Styringsenhed.h"

using namespace std; 

class UC1
{
public:
	UC1(Startknap* SK,Display *D,SumoBot *S1,SumoBot *S2,Styringsenhed *SE1, Styringsenhed *SE2);
	void run();
	~UC1();
private:
	Startknap* _SK; 
	Display* _D;
	SumoBot* _SB1; 
	SumoBot* _SB2;
	Styringsenhed* _SE1; 
	Styringsenhed* _SE2; 
};

