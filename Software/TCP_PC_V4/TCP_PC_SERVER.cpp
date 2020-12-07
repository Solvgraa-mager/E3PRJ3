#include "TCPServer.h"

 
 TCPServer::TCPServer()
{
   bytesReceived = 0;
}

int TCPServer::openServer(int port)
{
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }

    cout << "socket created" << endl;
 
    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
 
    bind(listening, (sockaddr*)&hint, sizeof(hint));

    
 
    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

     cout << "listen on socket" << endl;


 
    // Wait for a connection
    cout << "Wait for a connection" << endl;
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    
    cout << "about to accept client on socket" << endl;

    clientSocket_ = accept(listening, (sockaddr*)&client, &clientSize);
 
    cout << "accept client on socket" << endl;

    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
 
    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 

    cout << "memset Host and Service" << endl;


    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
 
    // Close listening socket
    close(listening);

    return 0;
}  

int TCPServer::sendMsg(string msg)
{

    // Echo message back to client
    send(clientSocket_, msg, sizeof(msg) + 1, 0);

	return 0;
}


int TCPServer::receiveMsg()
{

    memset(TCP::getBuffer(), 0, 4096);//buffer fyldes med 0;
    bytesReceived = recv(clientSocket_, TCP::getBuffer(), 4096, 0);
	
    if (bytesReceived == -1)
    {
        cerr << "Error in TCP_Server recv(). Quitting" << endl;
        return -1;
    }
 
    if (bytesReceived == 0)
    {
            cout << "Client disconnected " << endl;
            return -2;
    }
 
    cout << string(TCP::getBuffer(), 0, bytesReceived) << endl;
 
    
    
    return 0;
}

int TCPServer::closeServer()
{
     // Close the socket
    close(clientSocket_);
    return 0;
}

TCPServer::~TCPServer()
{
   
}