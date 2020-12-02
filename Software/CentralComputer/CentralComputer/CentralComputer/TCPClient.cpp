#include "TCPClient.h"


TCPClient::TCPClient(string IP, int port)
{
	//	Create a socket
    cout << "TCPClient Constructor envoked" << endl;
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    cout << "socket_ = " << socket_ << endl;
	TCP::setPort(port); 
	IP_ = IP;
    cout << "IP set to: " << IP_ << endl;
}

int TCPClient::connectToServer()
{
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port_);
    inet_pton(AF_INET, IP_.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(socket_, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }

	return 0;
}

int TCPClient::disconnect()
{
	close(socket_);
	return 0;
}

TCPClient::~TCPClient()
{

}
