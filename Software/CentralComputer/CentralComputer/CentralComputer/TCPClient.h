#pragma once
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
	string IP; 
	int socket;	
};

