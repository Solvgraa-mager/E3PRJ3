#include "MotorstyringIF.h"

/// MotorstyringIFStart
MotorstyringIF::MotorstyringIF()
{
	// init og gpio ports using wirinPi
	//HW-PWM GPIO12: PWM0, PGIO13: PWM1
	wiringPiSetup(); //wiringPi pin setup
	pinMode(26, PWM_OUTPUT); //PWM0 BCM32
	pinMode(23, PWM_OUTPUT); //PWM1 BCM33

	pinMode(22, OUTPUT); //input1 BCM31
	pinMode(21, OUTPUT); //input2 BCM29
	pinMode(4, OUTPUT); //input3 BCM16
	pinMode(5, OUTPUT); //input4 BCM18

	pwmWrite(26, 0); //reset HardWarePWMvalue
	pwmWrite(23, 0); //reset HardWarePWMvalue
}
/// MotorstyringIFStop

/// setSpeedDirStart
void MotorstyringIF::setSpeedDir(char *speedDir)
{
	// Sets default values
		int Derection = 0; int PWM_Size = 0; int ValueDerection = 0; int Angle_Size = 0;     
		int DerectionAngle = 0; int ValueAngle = 0; int MotorV; int MotorH;
		int Input1, Input2, Input3, Input4;

		// Checks if first char is a minus "-" and put anwser in  "Derection"
		if (speedDir[0] == '-') { Derection = 1; Input1 = 1; Input3 = 1; Input2 = 0; Input4 = 0; } 
		else { Derection = 0; Input1 = 0; Input3 = 0; Input2 = 1; Input4 = 1; }                    

		// Running the char array through and checking for number of places before "|"
		// And adding the value to "PWM_Size"
		for (int i = 0 + Derection; i < 3 + Derection; i++)         
		{														
			PWM_Size++;
			if (speedDir[i] == '|')	// Breaks if the loop hits "|" and subtracts "PWM_Size" with one, cause the "|" char placement dosent count 							 
			{
				i = 5; PWM_Size--;
			}
		}

		// Checks if the first Char after "|" is a minus "-" and puts the anwser in "DerectionAngle"
		if (speedDir[PWM_Size + 1 + Derection] == '-') { DerectionAngle = 1; }
		else { DerectionAngle = 0; }

		// Calculating the size og "Angle_Sixe"
		Angle_Size = sizeof(speedDir) - PWM_Size - Derection - DerectionAngle - 2;      

		// Calculating the int value for Angle part of the char array and puts it into "ValueAngle"
		for (int i = sizeof(speedDir) - Angle_Size - 1; i < sizeof(speedDir) - 1; i++)  
		{ValueAngle = (ValueAngle * 10) + ((int)speedDir[i] - '0');}

		// Calculating the int value for Derection part of char array and puts it into "ValueDerection"
		for (int i = 0 + Derection; i < PWM_Size + Derection; i++)     
		{ValueDerection = (ValueDerection * 10) + ((int)speedDir[i] - '0');}


		if (ValueAngle != 0)					// Hvis "Angle" er alt andet end 0 = "Bilen korer ikke ligeud" sottes motorenes PWM efter dette
		{
			if (ValueAngle < 0) {			// Bilen korer med - grader = "SumoBotten korer mod venstre"
				MotorH = ValueDerection;
				MotorV = ValueDerection * cos(ValueAngle * PI / 180); // PWM justering udregnes efter vinklen
			}
			else {							// Bileb korer med + grader = "SumoBotten korer mod "hojre"
				MotorV = ValueDerection;
				MotorH = ValueDerection * cos(ValueAngle * PI / 180); // PWM justering udregnes efter vinklen
			}
		}
		else { MotorH = ValueDerection; MotorV = ValueDerection; } // Hvis angleDerection er = 0 "SumoBotten korer ligeud" sottes begge motorenes PWM til verdien af hastigheden

		digitalWrite(22, Input1); // input pindene settes så motorstyringen ved hvilken retning den skal køre
		digitalWrite(21, Input2);
		digitalWrite(4, Input3);
		digitalWrite(5, Input4);

		pwmWrite(26, MotorV*10); // PWM pindene settes og ganges med 10 da "WiringPie" har maks PWM på 1024 og der anvendes maks pwn på 100 i koden. (100 * 10 = 1000)
		pwmWrite(23, MotorH*10); // Sa maks PWM er 24 under det maksimale mulige.
};
/// setSpeedDirStop
