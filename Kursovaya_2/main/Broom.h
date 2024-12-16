#pragma once
#include "Air.h"
class Broom : public Air
{
public:
	Broom();
	Broom(std::string s_name, int s_speed);
	double travel_time(int distance) override;
};

