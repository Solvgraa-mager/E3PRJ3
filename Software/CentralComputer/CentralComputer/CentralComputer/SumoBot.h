#pragma once
class SumoBot
{
public:
	SumoBot();
	bool setDirectionAndSpeed(int dir, int speed);
	int substractLife();
	int getLife();
	~SumoBot();
private:
	int _lifes;
	int _retning;
	int _speed; 
	bool _attackStatus;
};

