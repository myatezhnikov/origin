#pragma once
#include "..\lib1.2\Ground.h"
class Centaur :  public Ground
{
public:
	Centaur();
	Centaur(std::string s_name, int s_speed, int time);
	double travel_time(int distance) override;
};

