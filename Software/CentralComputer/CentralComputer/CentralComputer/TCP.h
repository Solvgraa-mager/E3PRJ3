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

using namespace std;

class TCP :
	public Wifi
{
public:
	TCP();
	int send(string msg) override;
	int getPort(); 
	void setPort(int port);
	char* getBuffer();
	int receive() override;
	~TCP();
private:
	int port_; 
	int buffer_size_;
	char buffer[MAX_BUFFER_SIZE]_; 
};