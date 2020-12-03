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
	const char _IP[sizeof("0.0.0.0")] = "0.0.0.0";
    sockaddr_in _hint[MAX_CLIENT_COUNT];
	int clientSocket_[MAX_CLIENT_COUNT]; 
	int clientCount_;
};

