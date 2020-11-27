#include "TCPClient.h"


TCPClient::TCPClient(string IP, int port)
{
	//	Create a socket
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
	TCP::setPort(port); 
	IP_ = IP;
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

	//	While loop:
    string userInput;


    do {
        //		Enter lines of text
        cout << "> ";
        getline(cin, userInput);

        //		Send to server
        int sendRes = send(socket_, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
            continue;
        }

        //		Wait for response
        memset(TCP::buffer, 0, 4096);
        int bytesReceived = recv(socket_, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {
            //		Display response
            cout << "SERVER> " << string(buf, bytesReceived) << "\r\n";
        }
    } while(true);

    //	Close the socket
    close(sock);

	return 0;
}

int TCPClient::disconnect()
{
	return 0;
}

TCPClient::~TCPClient()
{

}
