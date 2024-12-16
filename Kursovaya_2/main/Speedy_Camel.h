#pragma once
#include "Ground.h"
class Speedy_Camel : public Ground
{
public:
	Speedy_Camel(std::string s_name, int s_speed, int time);
	Speedy_Camel();
	double travel_time(int distance) override;
};

