#pragma once
#include "Air.h"
class Eagle : public Air
{
public:
	Eagle();
	Eagle(std::string s_name, int s_speed);
	double travel_time(int distance) override;
};

