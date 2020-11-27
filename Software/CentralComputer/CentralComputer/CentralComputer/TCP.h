#pragma once
#include "Wifi.h"

class TCP :
	public Wifi
{
public:
	TCP();
	int send() override;
	int receive() override;
	~TCP();
private:
	int port; 
	int buffer_size;
	char buffer[BUFFER_SIZE]; 
};

