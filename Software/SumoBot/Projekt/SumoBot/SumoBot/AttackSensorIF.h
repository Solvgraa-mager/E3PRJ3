#pragma once
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <fcntl.h>

#define attack_buf_SIZE 1024

using namespace std;

class AttackSensorIF
{
public:
	AttackSensorIF(); //Constructor
	~AttackSensorIF(); //Destructor
	bool getAttackStatus();
private:
	int attackStatus_; // used to remember last number of interrupts
};

