#include "Startknap.h"
#include "iostream"
#include <fcntl.h>
#include <unistd.h>


using namespace std;

Startknap::Startknap(int gpio1, int gpio2)
{
	_gpio[0] = gpio1;
	_gpio[1] = gpio2;
	_status[0] = false;
	_status[1] = false;

	string prefix = "echo "; 
	string postfix = " > /sys/class/gpio/export";
	string exportGpioCall = prefix + to_string(_gpio[0]) + postfix;
	system(exportGpioCall.c_str());
	exportGpioCall = prefix + to_string(_gpio[1]) + postfix;
	system(exportGpioCall.c_str());	
}

void Startknap::waitForStart()
{
	string path; 
	string prefix = "/sys/class/gpio/gpio";
	string postfix = "/value";
	char readBuffer;
	_status[0] = false, _status[1] = false;

	//Loop terminates when both players' status are 1 otherwise busy waiting for them
	while (_status[0] != true || _status[1] != true)
	{
		//Sets _status-array with 1's for ready player
		for (int i = 0; i < 2; i++)
			{
				path = prefix+to_string(_gpio[i])+postfix;
				int gpio_fd = open(path.c_str(),O_RDONLY);
				read(gpio_fd,&readBuffer,1);
				_status[i] = (readBuffer - '1' ? true : _status[i]);
				close(gpio_fd);
			}
	}
	cout << "STARTKNAP: Both players ready" << endl; 
}

Startknap::~Startknap()
{
	//GPIOs free'd
	string prefix = "echo "; 
	string postfix = "> /sys/class/gpio/unexport";
	string exportGpioCall = prefix + to_string(_gpio[0]) + postfix;
	system(exportGpioCall.c_str());
	exportGpioCall = prefix + to_string(_gpio[1]) + postfix;
	system(exportGpioCall.c_str());	
}
