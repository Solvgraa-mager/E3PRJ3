#pragma once
#include <iostream>

#define BUFFER_SIZE 4096
#define CLIENT_COUNT 2

using namespace std; 

class Communication
{
public:
	Communication();
	virtual int send() = 0;
	virtual int receive() = 0;
	~Communication();
private:
};

