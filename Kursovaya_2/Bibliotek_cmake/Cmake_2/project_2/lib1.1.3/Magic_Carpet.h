#pragma once
#include "..\lib1.1\Air.h"

class Magic_Carpet : public Air
{
public:
	Magic_Carpet();
	Magic_Carpet(std::string s_name, int s_speed);
	double travel_time(int distance) override;
};

