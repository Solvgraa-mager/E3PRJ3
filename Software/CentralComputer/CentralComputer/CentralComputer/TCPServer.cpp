#include "TCPServer.h"

TCPServer::TCPServer(int clientCount)
{
    cout << "TCPServer constructed with clientCount = " << clientCount << endl;
	clientCount_ = clientCount;
}

int TCPServer::openServer()
{
    cout << "openServer envoked" << endl;
	int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }
    cout << "Created socket with no " << listening << endl;
     
    // Bind the ip address and port to a socket
    _hint[0].sin_family = AF_INET;
    cout << "Hint sin_family set to " << _hint[0].sin_family << endl; 
    _hint[0].sin_port = htons(TCP::getPort());//Get port nummer fra TCP classen.
    cout << "Hint sin_port set to " << _hint[0].sin_port << endl; 

    inet_pton(AF_INET, _IP, &_hint[0].sin_addr);
    cout << "IP set to: " << _IP << endl;
 
    int err = bind(listening, (sockaddr*)&_hint[0], sizeof(_hint[0]));
    cout << "bind returns: " << err << endl;
 
    // Tell Winsock the socket is for listening
    err = listen(listening, SOMAXCONN);
    cout << "Socket set to listening socket with return val: " << err << endl;
 
    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
 
    clientSocket_[clientCount_] = accept(listening, (sockaddr*)&client, &clientSize);
 
    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
 
    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 
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

int TCPServer::closeServer()
{
	close(clientSocket_[clientCount_]);
	return 0;
}

TCPServer::~TCPServer()
{
	closeServer();
}
