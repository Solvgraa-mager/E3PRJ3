#include <string.h>
#include <iostream>
#include <unistd.h>
#include "AttackSensorIF.h"

using namespace std;

int main(void)
{
	AttackSensorIF Sensor;

	while(1)
	{
	cout << "getAttackStatus called. New interrupt?";
	if(Sensor.getAttackStatus() == 1)
	{
		cout << " yes" << endl;
	}
	else
	{
		cout << " no" << endl;
	}
	sleep(2);
	}


	return 0;
	
}