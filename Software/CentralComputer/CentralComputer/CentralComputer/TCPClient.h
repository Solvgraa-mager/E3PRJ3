#pragma once
#include "TCP.h"

#include "TCP.h"

class TCPClient :
	public TCP
{
public:
	TCPClient(string IP, int port_input);
	int connectToServer(); 
	int disconnect();
	~TCPClient();
private:
    sockaddr_in _hint;
	string IP_; 
	int port_; 
	int socket_;	
};

