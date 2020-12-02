#pragma once

#include "TCP.h"

class TCPServer :
	public TCP
{
public:
	TCPServer(int clientCount);
	int openServer();
	int closeServer();

	~TCPServer();
private: 
	int clientSocket_[MAX_CLIENT_COUNT]; 
	int clientCount_; 
};

