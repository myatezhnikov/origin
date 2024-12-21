#pragma once
#include "..\\lib1.2\Ground.h"
class All_terrain_boots : public Ground
{
public:
	All_terrain_boots(std::string s_name, int s_speed, int time);
	All_terrain_boots();
	double travel_time(int distance) override;
};

