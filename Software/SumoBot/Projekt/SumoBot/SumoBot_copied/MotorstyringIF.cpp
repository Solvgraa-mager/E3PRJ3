#include "MotorstyringIF.h"

/// MotorstyringIFStart
MotorstyringIF::MotorstyringIF()
{
	// init af gpio porte j�vnf�r wirinPi
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
		int Derection = 0; int PWM_Size = 0; int ValueDerection = 0; int Angle_Size = 0;     // S�tter v�rdier til default
		int DerectionAngle = 0; int ValueAngle = 0; int MotorV; int MotorH;
		int Input1, Input2, Input3, Input4;

		if (speedDir[0] == '-') { Derection = 1; Input1 = 1; Input3 = 1; Input2 = 0; Input4 = 0; }     // Checker om der er negativ eller positiv fortegn og s�tter "Derection" derefter
		else { Derection = 0; Input1 = 0; Input3 = 0; Input2 = 1; Input4 = 1; }      

		for (int i = 0 + Derection; i < 3 + Derection; i++)         // L�ber Char arrayet igennem og checker antal pladser der er f�r "|"
		{															// Og ti�f�jer v�rdien af dette til "PWM_Size"
			PWM_Size++;

			if (speedDir[i] == '|')										// Breaker hvis loopet m�der "|" og tr�kker denne plads fra PWM_Size da "|" ikke skal t�lles med
			{
				i = 5; PWM_Size--;
			}
		}

		if (speedDir[PWM_Size + 1 + Derection] == '-') { DerectionAngle = 1; }         // Checker om der er negativ fortegn og s�tter "DerectionAngle" derefter
		else { DerectionAngle = 0; }

		Angle_Size = sizeof(speedDir) - PWM_Size - Derection - DerectionAngle - 2;            // Beregner st�relsen af Angle_Size

		for (int i = sizeof(speedDir) - Angle_Size - 1; i < sizeof(speedDir) - 1; i++)   // Omregner Char til int og l�gger v�rdien ind i ValueAngle
		{ValueAngle = (ValueAngle * 10) + ((int)speedDir[i] - '0');}


		for (int i = 0 + Derection; i < PWM_Size + Derection; i++)          // Omregner Char til int og l�gger v�rdien ind i ValueDerection
		{ValueDerection = (ValueDerection * 10) + ((int)speedDir[i] - '0');}


		if (ValueAngle != 0)					// Hvis "Angle" er alt andet end 0 = "Bilen k�rer ikke ligeud" s�ttes motorenes PWM efter dette
		{
			if (ValueAngle < 0) {			// Bilen k�rer med - grader = "SumoBotten k�rer mod venstre"
				MotorH = ValueDerection;
				MotorV = ValueDerection * cos(ValueAngle * PI / 180); // PWM justering udregnes efter vinklen
			}
			else {							// Bileb k�rer med + grader = "SumoBotten k�rer mod "h�jre"
				MotorV = ValueDerection;
				MotorH = ValueDerection * cos(ValueAngle * PI / 180); // PWM justering udregnes efter vinklen
			}
		}
		else { MotorH = ValueDerection; MotorV = ValueDerection; } // Hvis angleDerection er = 0 "SumoBotten k�rer ligeud" s�ttes begge motorenes PWM til v�rdien af hastigheden

		digitalWrite(22, Input1); // input pindene s�ttes s� motorstyringen ved hvilken retning den skal k�re
		digitalWrite(21, Input2);
		digitalWrite(4, Input3);
		digitalWrite(5, Input4);

		pwmWrite(26, MotorV*10); // PWM pindene s�ttes og ganges med 10 da "WiringPie" har maks PWM p� 1024 og der anvendes maks pwn p� 100 i koden. (100 * 10 = 1000) s�
		pwmWrite(23, MotorH*10); // S� maks PWM er 24 under det maksimale mulige.
};
/// setSpeedDirStop
