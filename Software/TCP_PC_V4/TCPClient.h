#pragma once
#include "TCP.h"
#include "TCP.h"

#define MAX_SERVER_COUNT 2

class TCPClient :
	public TCP
{
public:
	TCPClient();
	int connectToServer(string Ipaddress, int port); 
	int disconnectToServer(int serverNr);
	int sendMsg(string msg) override;
	int receiveMsg() override;
	~TCPClient();
private:
	string ipAddress_; 
	int socket_[MAX_SERVER_COUNT];	
	int port_[MAX_SERVER_COUNT];
	int serverCount;
	int activeServer;
	string userInput_;
};

