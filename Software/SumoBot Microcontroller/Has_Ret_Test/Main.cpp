#include <iostream>
#include <string.h>
#include<stdio.h>
#include <math.h>

#define PI 3.14159265

using namespace std;

     const char C1[] = {'-','7','7','|','-','4','5', '\0' }; 
	// const char C1[] = {'7','|', '-','4','5', '\0' };
	// const char C1[] = { '-','1','0','0','|', '-','7','0', '\0' };
    // const char C1[] = { '1','0','0','|','1','0', '\0' };
	// const char C1[] = { '0','|','0', '\0' };

int main()
{
	int Derection = 0; int PWM_Size = 0; int ValueDerection = 0; int Angle_Size = 0;     // Sætter værdier til default
	int DerectionAngle = 0; int ValueAngle = 0; int MotorV ; int MotorH ;
	int Input1, Input2, Input3, Input4;

	if (C1[0] == '-') { Derection = 1; Input1 = 1; Input3 = 1; Input2 = 0; Input4 = 0; }     // Checker om der er negativ fortegn og sætter "Derection" derefter
	else {Derection = 0; Input1 = 0; Input3 = 0; Input2 = 1; Input4 = 1;}

	for (int i = 0 + Derection; i < 3 + Derection; i++)         // Løber Char arrayet igennem og checker antal pladser der er før "|"
	{															// Og tiøfæjer vlrdien til "PWM_Size"
		PWM_Size++;

		if (C1[i] == '|')										// Breaker hvis 
		{i = 5; PWM_Size--;}
	}

	if (C1[PWM_Size + 1 + Derection] == '-') { DerectionAngle = 1; }         // Checker om der er negativ fortegn og sætter "Derection" derefter
	else { DerectionAngle = 0; }

	Angle_Size = sizeof(C1) - PWM_Size - Derection - DerectionAngle - 2;            // Beregner størelsen af Angle_Size

	for (int i = sizeof(C1) - Angle_Size - 1 ; i < sizeof(C1)-1; i++)   // Omregner Char til int og lægger værduen ind i ValueAngle
	{ValueAngle = (ValueAngle * 10) + ((int)C1[i] - '0');}


	for (int i = 0 + Derection; i < PWM_Size + Derection; i++)          // Omregner Char til int og lægger værduen ind i ValueDerection
	{ValueDerection = (ValueDerection * 10) + ((int)C1[i] - '0');}

	if (ValueAngle != 0)
	{
		if (ValueAngle < 0) {
			MotorH = ValueDerection;
			MotorV = ValueDerection * cos(ValueAngle * PI / 180);
		}
		else {
			MotorV = ValueDerection;
			MotorH = ValueDerection * cos(ValueAngle * PI / 180);
		}
	}
	else { MotorH = ValueDerection; MotorV = ValueDerection;}


	cout << "Input C1: " << C1 << endl;
	cout <<"MotorV PWM %: " << MotorV << endl;
	cout <<"MotorH PWM %: " << MotorH << endl;
	cout << "Derection  'Frem = 0, Tilbage = 1' : " <<  Derection << endl;
	cout << "Input 1: " << Input1 << endl;
	cout << "Input 2: " << Input2 << endl;
	cout << "Input 3: " << Input3 << endl;
	cout << "Input 4: " << Input4 << endl;

	return 0;
}