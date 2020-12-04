#pragma once
class Startknap
{
public:
	Startknap();
	void waitForStart();
	~Startknap();
private:
	bool _status;
};

