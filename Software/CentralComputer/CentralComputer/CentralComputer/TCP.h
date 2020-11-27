#pragma once
#include "Wifi.h"

class TCP :
	public Wifi
{
public:
	TCP();
	int send(string msg) override;
	int receive() override;
	~TCP();
private:
	int port; 
	int buffer_size;
	char buffer[MAX_BUFFER_SIZE]; 
};