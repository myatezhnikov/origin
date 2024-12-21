#pragma once
#include"..\lib1.2\Ground.h"

class Camel : public Ground
{
public:
	Camel();
	Camel(std::string name, int speed, int time);
	~Camel();
	double travel_time(int distance) override;
private:

};


