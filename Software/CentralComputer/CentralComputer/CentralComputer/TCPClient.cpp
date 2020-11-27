#include "TCPClient.h"

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

TCPClient::TCPClient(string IP, int port_input)
{
	//	Create a socket
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
	port = port_input; 
}

int TCPClient::connectToServer()
{
	//	Create a hint structure for the server we're connecting with
    int port = 54000;
    string ipAddress = "192.168.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }

	return 0;
}

int TCPClient::disconnect()
{
	return 0;
}

TCPClient::~TCPClient()
{

}
