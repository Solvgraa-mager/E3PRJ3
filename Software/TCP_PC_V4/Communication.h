#pragma once
#include <iostream>

#define MAX_BUFFER_SIZE 4096
#define MAX_CLIENT_COUNT 2

using namespace std; 

class Communication
{
public:
	Communication();
	virtual int sendMsg(string msg) = 0; 
	virtual int receiveMsg() = 0; 
	~Communication();
private:
};

