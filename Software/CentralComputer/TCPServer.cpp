#include "TCPServer.h"

 
 TCPServer::TCPServer()
{

}

int TCPServer::openServer(int port)
{
    // create socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
        return -1; //socket faild create
 
    //give socket an IP-address and port to bind
    sockaddr_in serverStructure; //create socket object from sock_in stuckaddr_in 
    serverStructure.sin_family = AF_INET; // AF_INET standart is used
    serverStructure.sin_port = htons(port); //insert used port to socket object
    inet_pton(AF_INET, "0.0.0.0", &serverStructure.sin_addr); //Inet function******
 
    bind(listening, (sockaddr*)&serverStructure, sizeof(serverStructure));//binding socket to address

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);
 
    // Wait for a connection
    cout << "Wait for a connection" << endl;
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    
    cout << "about to accept client on socket" << endl;

    clientSocket_ = accept(listening, (sockaddr*)&client, &clientSize);

    cout << "accept client on socket" << endl;

//*******************DET SKAL JEG LIGE FATTE**************************
    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
 
    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 //*******************DET SKAL JEG LIGE FATTE**************************

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
    int err = send(clientSocket_, msg.c_str(), msg.size() + 1, 0);
    if (err == -1)
        return -1;
	return 0;
}


int TCPServer::receiveMsg(char *buffer, int bufferLength)
{

    memset(buffer, 0, length);//buffer fyldes med 0;
    int bytesReceived = recv(clientSocket_, buffer, length, 0);
	
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
 
    cout << string(buffer, 0, bytesReceived) << endl;
 
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