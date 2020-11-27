#pragma once
#include "TCP.h"
class TCPServer :
	public TCP
{
public:
	TCPServer();
	int openServer();
	int closeServer();
	~TCPServer();
private: 
	int Socket[CLIENT_COUNT]; 
	int clientCount; 
};

