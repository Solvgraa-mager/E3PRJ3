#pragma once
class SumoBot
{
	SumoBot();
	int setDirectionAndSpeed(int dir, int speed);
	int substractLife();
	int getLife();
	~SumoBot();
private:
	int _lifes;
	int _retning;
	int _speed; 
	bool _attackStatus;
};

