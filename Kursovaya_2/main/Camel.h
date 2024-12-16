#pragma once
//#include"Camel.h"
#include"Ground.h"
//#include"Transport.h"
class Camel : public Ground
{
public:
	Camel();
	Camel(std::string name, int speed, int time);
	~Camel();
	double travel_time(int distance) override;
private:

};


