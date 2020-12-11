#include <iostream>
#include <string.h>
#include<stdio.h>


using namespace std;

    // const char C1[] = {'-','7','7','|','-','4','5', '\0' }; 
	// const char C1[] = {'7','|', '-','4','5', '\0' };
	 const char C1[] = { '-','1','0','0','|', '-','7','0', '\0' };
    // const char C1[] = { '1','0','0','|','4','5', '\0' };
	// const char C1[] = { '0','|','0', '\0' };
int main()
{
	int Derection = 0; int PWM_Size = 0; int ValueDerection = 0; int Angle_Size = 0; int DerectionAngle = 0; int ValueAngle = 0; // Sætter værdier til 0

	if (C1[0] == '-') { Derection = 1; }                        // Checker om der er negativ fortegn og sætter "Derection" derefter
	else { Derection = 0; }

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


	if (Derection == 1) { ValueDerection = ValueDerection * (-1);}     // Ganger med -1 for at få negativ fortegn hvis der er negativ fortegn i "Derection"
	if (DerectionAngle == 1) { ValueAngle = ValueAngle * (-1);}        // Ganger med -1 for at få negativ fortegn hvis der er negativ fortegn i "DerectionAngle"


	cout << ValueDerection << endl; 
	cout << ValueAngle << endl;



	return 0;
}