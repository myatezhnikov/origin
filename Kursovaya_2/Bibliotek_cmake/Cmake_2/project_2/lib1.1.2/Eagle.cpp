#include "Eagle.h"
Eagle::Eagle()
{
	name = "���", speed = 8;
}
Eagle::Eagle(std::string s_name, int s_speed)
{
	name = s_name, speed = s_speed;
}
double Eagle::travel_time(int distance)
{ 
	return (distance / get_Speed() * 0.94); // ���������� ���������� ������ 6%
}