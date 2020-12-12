#pragma once
#include "TCP.h"

class TCPServer :
	public TCP
{
public:
	TCPServer();
	int openServer(int port);
	int closeServer();
	int sendMsg(string msg) override;
	int receiveMsg(char *buffer, int length) override;
	~TCPServer();
private: 
	int clientSocket_; 
};

