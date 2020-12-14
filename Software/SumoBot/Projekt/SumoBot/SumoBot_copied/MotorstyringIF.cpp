#include "MotorstyringIF.h"

/// MotorstyringIFStart
MotorstyringIF::MotorstyringIF()
{
	// init af gpio porte jævnfør wirinPi
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
		int Derection = 0; int PWM_Size = 0; int ValueDerection = 0; int Angle_Size = 0;     // Sætter værdier til default
		int DerectionAngle = 0; int ValueAngle = 0; int MotorV; int MotorH;
		int Input1, Input2, Input3, Input4;

		if (speedDir[0] == '-') { Derection = 1; Input1 = 1; Input3 = 1; Input2 = 0; Input4 = 0; }     // Checker om der er negativ eller positiv fortegn og sætter "Derection" derefter
		else { Derection = 0; Input1 = 0; Input3 = 0; Input2 = 1; Input4 = 1; }      

		for (int i = 0 + Derection; i < 3 + Derection; i++)         // Løber Char arrayet igennem og checker antal pladser der er før "|"
		{															// Og tiøfæjer værdien af dette til "PWM_Size"
			PWM_Size++;

			if (speedDir[i] == '|')										// Breaker hvis loopet møder "|" og trækker denne plads fra PWM_Size da "|" ikke skal tælles med
			{
				i = 5; PWM_Size--;
			}
		}

		if (speedDir[PWM_Size + 1 + Derection] == '-') { DerectionAngle = 1; }         // Checker om der er negativ fortegn og sætter "DerectionAngle" derefter
		else { DerectionAngle = 0; }

		Angle_Size = sizeof(speedDir) - PWM_Size - Derection - DerectionAngle - 2;            // Beregner størelsen af Angle_Size

		for (int i = sizeof(speedDir) - Angle_Size - 1; i < sizeof(speedDir) - 1; i++)   // Omregner Char til int og lægger værdien ind i ValueAngle
		{ValueAngle = (ValueAngle * 10) + ((int)speedDir[i] - '0');}


		for (int i = 0 + Derection; i < PWM_Size + Derection; i++)          // Omregner Char til int og lægger værdien ind i ValueDerection
		{ValueDerection = (ValueDerection * 10) + ((int)speedDir[i] - '0');}


		if (ValueAngle != 0)					// Hvis "Angle" er alt andet end 0 = "Bilen kører ikke ligeud" sættes motorenes PWM efter dette
		{
			if (ValueAngle < 0) {			// Bilen kører med - grader = "SumoBotten kører mod venstre"
				MotorH = ValueDerection;
				MotorV = ValueDerection * cos(ValueAngle * PI / 180); // PWM justering udregnes efter vinklen
			}
			else {							// Bileb kører med + grader = "SumoBotten kører mod "højre"
				MotorV = ValueDerection;
				MotorH = ValueDerection * cos(ValueAngle * PI / 180); // PWM justering udregnes efter vinklen
			}
		}
		else { MotorH = ValueDerection; MotorV = ValueDerection; } // Hvis angleDerection er = 0 "SumoBotten kører ligeud" sættes begge motorenes PWM til værdien af hastigheden

		digitalWrite(22, Input1); // input pindene sættes så motorstyringen ved hvilken retning den skal køre
		digitalWrite(21, Input2);
		digitalWrite(4, Input3);
		digitalWrite(5, Input4);

		pwmWrite(26, MotorV*10); // PWM pindene sættes og ganges med 10 da "WiringPie" har maks PWM på 1024 og der anvendes maks pwn på 100 i koden. (100 * 10 = 1000) så
		pwmWrite(23, MotorH*10); // Så maks PWM er 24 under det maksimale mulige.
};
/// setSpeedDirStop
