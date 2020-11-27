#pragma once
#include "TCP.h"

#include "TCP.h"

class TCPClient :
	public TCP
{
public:
	TCPClient();
	int connectToServer(); 
	int disconnect();
	~TCPClient();
private:
	string IP_; 
	int port_; 
	int socket_;	
};

