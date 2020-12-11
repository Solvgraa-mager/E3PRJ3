
#include "TCPClient.h"

TCPClient::TCPClient()
{
   socket_ = 0;
}


int TCPClient::connectToServer(string ipAddress, int port)
{

    //	Create a socket
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_ == -1)
    {
        return 1;
    }
    else
    {
        cout << "socket number is: " << socket << endl;
    }

    //	Create a hint structure for the server we're connecting with

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(socket_, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }


    return 0;
}

int TCPClient::disconnectToServer()
{

   //	Close the socket
    close(socket_);
    return 0;
}

int TCPClient::sendMsg(string msg)
{
    //		Send to server
    int sendRes = send(socket_, msg.c_str(), msg.size() + 1, 0);
    if (sendRes == -1)
    {
        cout << "Could not send to server! Whoops!\r\n";
        return -1;
    }

    return 0;
}

int TCPClient::receiveMsg(char *buffer, int length)
{
    memset(buffer, 0, length); //empty buffer

    int bytesReceived = recv(socket_, buffer, length, 0); //fill buffer with message
    if (bytesReceived == -1)
    {
        cout << "There was an error getting response from server\r\n";
    }
    else
    {
        //		Display response
        cout << "SERVER> " << string(buffer, bytesReceived) << "\r\n";//print message
    }

    return 0;
    
}

TCPClient::~TCPClient()
{
    disconnectToServer();
}
