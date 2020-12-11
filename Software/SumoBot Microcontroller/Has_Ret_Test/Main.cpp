#include <iostream>
#include <string.h>
#include<stdio.h>


using namespace std;


int main()
{
	int Derection;
	int PWM_Size = 0;
	//const char C1[] = {'-','7','7','|', '-','4','5', '\0' };
	//const char C1[] = {'7','|', '-','4','5', '\0' };

	char C1[] = { '-','9','9','1','|', '-','4','5', '\0' };
	//const char C1[] = {'1','0','0','|', '-','4','5', '\0' };

	if (C1[0] == '-') { Derection = 1; }
	else { Derection = 0; }

	int ValueDerection = 0; //= (int)C1[0 + Derection] - '0';

	for (int i = 0 + Derection; i < 3+Derection; i++)
	{
		PWM_Size++;
		if (C1[i] == '|')
		{
			i = 5;
			PWM_Size--;
		}
		ValueDerection = (ValueDerection * 10) + ((int)C1[i] - '0');
	}

	if (Derection == 1) { ValueDerection = ValueDerection * (-1);}

	cout << "Derection = " << Derection << endl;
	cout << "PWM_Zize = " << PWM_Size << endl;
	cout << ValueDerection << endl;

	//cout << "ValuePWM = " << ValuePWM;

	//if (C1[0] == '-') { Derection = 1; }
	//else { Derection = 0; }
	//int Value = (int)C1[0+Derection] - 48;
	//int ValuePWM = (int)C1[0 + Derection] - 48;
	//int size_Char = sizeof(C1);
	//cout << size_Char << endl;
    //(ValueDerection)+((int)C1[i] - 48);
	//if (C1[i] == '|')
	//{
	//	 ValueDerection = ValueDerection + ((int)C1[i] - 48);
	//	cout << "hej";
	
	return 0;
}