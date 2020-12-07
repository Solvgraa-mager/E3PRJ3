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
	int receiveMsg() override;
	~TCPServer();
private: 
	const char _IP[sizeof("0.0.0.0")] = "0.0.0.0";
	int clientSocket_; 
	int bytesReceived;
};

