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
	//virtual int send(string msg) = 0;
	int getPort(); 
	void setPort(int port);
	char* getBuffer();
	//virtual int receive() = 0;
	~TCP();
private:
	int port_; 
	int buffer_size_;
	char buffer_[MAX_BUFFER_SIZE];
};