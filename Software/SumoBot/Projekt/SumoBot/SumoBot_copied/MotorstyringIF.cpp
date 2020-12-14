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
void MotorstyringIF::setSpeedDir(char *C1)
{
		int Derection = 0; int PWM_Size = 0; int ValueDerection = 0; int Angle_Size = 0;     // Sætter værdier til default
		int DerectionAngle = 0; int ValueAngle = 0; int MotorV; int MotorH;
		int Input1, Input2, Input3, Input4;

		if (C1[0] == '-') { Derection = 1; Input1 = 1; Input3 = 1; Input2 = 0; Input4 = 0; }     // Checker om der er negativ fortegn og sætter "Derection" derefter
		else { Derection = 0; Input1 = 0; Input3 = 0; Input2 = 1; Input4 = 1; }

		for (int i = 0 + Derection; i < 3 + Derection; i++)         // Løber Char arrayet igennem og checker antal pladser der er før "|"
		{															// Og tiøfæjer vlrdien til "PWM_Size"
			PWM_Size++;

			if (C1[i] == '|')										// Breaker hvis 
			{
				i = 5; PWM_Size--;
			}
		}

		if (C1[PWM_Size + 1 + Derection] == '-') { DerectionAngle = 1; }         // Checker om der er negativ fortegn og sætter "Derection" derefter
		else { DerectionAngle = 0; }

		Angle_Size = sizeof(C1) - PWM_Size - Derection - DerectionAngle - 2;            // Beregner størelsen af Angle_Size

		for (int i = sizeof(C1) - Angle_Size - 1; i < sizeof(C1) - 1; i++)   // Omregner Char til int og lægger værduen ind i ValueAngle
		{
			ValueAngle = (ValueAngle * 10) + ((int)C1[i] - '0');
		}


		for (int i = 0 + Derection; i < PWM_Size + Derection; i++)          // Omregner Char til int og lægger værduen ind i ValueDerection
		{
			ValueDerection = (ValueDerection * 10) + ((int)C1[i] - '0');
		}

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
		else { MotorH = ValueDerection; MotorV = ValueDerection; }

		digitalWrite(22, Input1);
		digitalWrite(21, Input2);
		digitalWrite(4, Input3);
		digitalWrite(5, Input4);

		pwmWrite(26, MotorV*10);
		pwmWrite(23, MotorH*10);
};
/// setSpeedDirStop
