#pragma once
#include "TCP.h"

class TCPClient :
	public TCP
{
public:
	TCPClient();
	int connectToServer(string Ipaddress, int port); 
	int disconnectToServer();
	int sendMsg(string msg) override;
	int receiveMsg(char *buffer, int lenght) override;
	~TCPClient();
private:
	int socket_;	
};

