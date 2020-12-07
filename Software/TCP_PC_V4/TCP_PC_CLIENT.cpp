
#include "TCPClient.h"

TCPClient::TCPClient()
{
   serverCount = 0;
   socket_[serverCount] = 0;
}


int TCPClient::connectToServer(string ipAddress, int port)
{
   

    //	Create a socket
    socket_[serverCount] = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_[serverCount] == -1)
    {
        return 1;
    }
    else
    {
        cout << "socket number is: " << socket << endl;
    }

    //	Create a hint structure for the server we're connecting with
    ipAddress_ = ipAddress; //gemmer IPadressen som en attribut.
    port_[serverCount] = port;

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port_[serverCount]);
    inet_pton(AF_INET, ipAddress_.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(socket_[serverCount], (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return 1;
    }


    serverCount++;

    return 0;
}

int TCPClient::disconnectToServer(int serverNr)
{

   //	Close the socket
    close(socket_[serverNr]);
    return 0;
}

int TCPClient::sendMsg(string msg)
{

    //		Enter lines of text
    cout << "> ";

    activeServer = stoi(msg.substr(0,msg.find(":")));

    //		Send to server
    int sendRes = send(socket_[activeServer], msg.c_str(), msg.size() + 1, 0);
    if (sendRes == -1)
    {
        cout << "Could not send to server! Whoops!\r\n";
        return -1;
    }


    return 0;
}

int TCPClient::receiveMsg()
{

 //		Wait for response
    memset(TCP::getBuffer(), 0, MAX_BUFFER_SIZE);
    int bytesReceived = recv(socket_[activeServer], TCP::getBuffer(), MAX_BUFFER_SIZE, 0);
    if (bytesReceived == -1)
    {
        cout << "There was an error getting response from server\r\n";
    }
    else
    {
        //		Display response
        cout << "SERVER> " << string(TCP::getBuffer(), bytesReceived) << "\r\n";
    }

    return 0;
    
}

TCPClient::~TCPClient()
{
    for(int i = 0; i<serverCount; i++)
        disconnectToServer(i);
}