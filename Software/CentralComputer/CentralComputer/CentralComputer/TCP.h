#pragma once
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
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