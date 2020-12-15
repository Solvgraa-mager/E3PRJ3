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

	/// AllocateGPIOStart
	//Allocate GPIO resources
	for (int i = 0; i < 2; i++)
	{
		string exportGpioCall = "echo " + to_string(_gpio[i]) + " > /sys/class/gpio/export";
		system(exportGpioCall.c_str());
	}
	/// AllocateGPIOStop
}


void Startknap::waitForStart()
{
	string path; 
	char readBuffer;
	_status[0] = false, _status[1] = false;

	/// waitForStartLoopStart
	//Loop terminates when both players' status are 1 otherwise busy waiting for them
	while (_status[0] != true || _status[1] != true)
	{
		//Sets _status-array with 1's for ready player
		for (int i = 0; i < 2; i++)
			{
				path = "/sys/class/gpio/gpio" +to_string(_gpio[i])+ "/value";
				//Open node in sysfs
				int gpio_fd = open(path.c_str(),O_RDONLY);
				//Read node
				read(gpio_fd,&readBuffer,1);
				//Update status only if pressed
				_status[i] = (readBuffer - '1' ? true : _status[i]);
				close(gpio_fd);
			}
	}
	/// waitForStartLoopStop
	cout << "STARTKNAP: Both players ready" << endl; 
}

Startknap::~Startknap()
{
	//Free GPIO's
	for (int i = 0; i < 2; i++)
	{
		string exportGpioCall = "echo " + to_string(_gpio[i]) + "> /sys/class/gpio/unexport";
		system(exportGpioCall.c_str());
	}

}
