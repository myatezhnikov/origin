#include "Magic_Carpet.h"
Magic_Carpet::Magic_Carpet()
{
	name = "Ковёр-самолёт", speed = 10;
}
Magic_Carpet::Magic_Carpet(std::string s_name, int s_speed)
{
	name = s_name, speed = s_speed;
}
double Magic_Carpet::travel_time(int distance)
{	
	//distance / get_Speed() -- время в пути
	if (distance < 1000) { return (distance / get_Speed()); }
	if (distance < 5000 ) { return (distance / get_Speed() * 0.97); }
	if (distance < 10000) { return (distance / get_Speed() * 0.9); }
	if (distance >= 10000) { return (distance / get_Speed() * 0.95); }
	else return 0;
}