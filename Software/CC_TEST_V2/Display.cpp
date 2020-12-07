#include "Display.h"
#include <string>
#include "wiringPi/wiringPi.h"
#include "wiringPi/devLib/lcd.h"

Display::Display(int rows, int cols, int bits, int rs, int strb, 
			int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
{
	_rows = rows; _cols = cols; _bits = bits; _rs = rs; _strb = strb;

	_data[0] = d0; _data[1] = d1; _data[2] = d2; _data[3] = d3;
	_data[4] = d4; _data[5] = d5; _data[6] = d6; _data[7] = d7;

	_displayfd = lcdInit(rows, cols, bits, rs, strb,
		_data[0], _data[0], _data[0], _data[0],
		_data[0], _data[0], _data[0], _data[0]);

}

void Display::startCountDown(int count)
{
	string msgToSend;
	for (int i = 0; i < count; i++)
	{
		//Center message on screen
		msgToSend = "\n   " + i;
		//Display message
		writeToScreen(msgToSend);
		sleep(1);
	}
}

void Display::lostLife(int player, SumoBot* S1, SumoBot* S2)
{
	//Define texts
	string prefix = " lost a life!\nLifes:\n";
	string P1text = "P1:  \n";
	string P2text = "P2:  ";
	//Concatenate texts
	string msg = to_string(player) + prefix+ to_string(S1->getLife())+P2text+to_string(S2->getLife());
	cout << "DISPLAY: Printing: " << msg << endl; 
	//Write to screen
	writeToScreen(msg);
}

void Display::showWinner(int winner)
{
	string prefix = "Winner\nis\n";
	string msg = prefix + to_string(winner);
}

int Display::writeToScreen(string msg)
{
	
	//Validate
	if (msg.length() > (_rows * _cols))
	{
		cout << "DISPLAY: Message too long to print" << endl; 
		return -1; 
	}
	/*					   */	
	/*   Write to screen   */
	/*                     */	
	
	int x, y;
	//Set LCD cursor to start
	lcdHome(_displayfd);

	for (int i = 0; i >= msg.length(); i++)
	{
		putchar(msg[i]);

		//Update position on display. Change line if x == _cols or new line char.
		if (x >= _cols || msg[i+1] == '\n')
		{
			y++;
			x = 0;
		}
		lcdPosition(_displayfd, x++, y);

		//If more than _rows new lines return
		if (y > _rows)
		{
			cout << "DISPLAY: Display only has " << _rows << endl;
			return -2;
		}
	}
	return 0;
}


