#pragma once
#include <iostream>
#include <string.h>
#include<stdio.h>
#include <math.h>
#include <wiringPi.h>

#define PI 3.14159265

using namespace std;

class MotorstyringIF
{
public:
	MotorstyringIF(); //Constructor
	void setSpeedDir(char *C1);
};