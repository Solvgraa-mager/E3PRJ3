#include "Display.h"
#include <string>
#include <unistd.h>
#include "wiringPi/wiringPi.h"
#include "wiringPi/lcd.h"

Display::Display(int rows, int cols, int bits, int rs, int strb, 
			int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
{

	_rows = rows; _cols = cols; _bits = bits; _rs = rs; _strb = strb;

	_data[0] = d0; _data[1] = d1; _data[2] = d2; _data[3] = d3;
	_data[4] = d4; _data[5] = d5; _data[6] = d6; _data[7] = d7;

	_displayfd = 0; 
	
	_displayfd = lcdInit(rows, cols, bits, rs, strb,
		_data[0], _data[0], _data[0], _data[0],
		_data[0], _data[0], _data[0], _data[0]);
	

}

void Display::startCountDown(int count)
{
	string msgToSend;
	for (int i = count; i <= 0; i--)
	{
		//Center message on screen
		msgToSend =to_string(i);
		//Display message
		writeToScreen(msgToSend);
		//Sleep 1 sec
		usleep(1000000);
	}
}

void Display::lostLife(int player, SumoBot* S1, SumoBot* S2)
{
	//Define texts
	string preprefix = "player "; 
	string prefix = " lost a life!\nLifes:\n";
	string P1text = "P1:  ";
	string P2text = "\nP2:  ";
	string newline = "\n";
	//Concatenate texts
	string msg = preprefix+to_string(player)+prefix+P1text+to_string(S1->getLife())+P2text+to_string(S2->getLife())+newline;
	//Write to screen
	writeToScreen(msg);
}

void Display::showWinner(int winner)
{
	string prefix = "Winner is ";
	string msg = prefix + to_string(winner);
	writeToScreen(msg);
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
	//Clear LCD screen
	lcdClear(_displayfd);
	//Set LCD cursor to start
	lcdHome(_displayfd);

	for (int i = 0; i <= msg.length(); i++)
	{
		//Null-termination = done
		if (msg[i] == '\0')
		{
			break;
		}
		//End of cols = new line
		if (x > _cols)
		{
			y++;
			x = 0;
			i--;
		}
		//New-line char == new line
		else if (msg[i] == '\n')
		{
			y++;
			x = 0;
		}
		//Else write to screen on position
		else
		{
			lcdPosition(_displayfd, x, y);
			putchar(msg[i]);
			x++;
		}
		if (y > _rows)
		{
			cout << "DISPLAY: Display only has " << _rows << endl;
			return -2;
		}
	}
	cout << "DISPLAY: " << msg << endl; 
	return 0;
}


