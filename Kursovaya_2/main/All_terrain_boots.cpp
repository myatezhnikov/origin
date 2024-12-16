#include "All_terrain_boots.h"
All_terrain_boots::All_terrain_boots()
{
	name = "�������-���������"; speed = 6; time_before_rest = 60; //���, ��������, ����� �������� �� ������
}
All_terrain_boots::All_terrain_boots(std::string s_name, int s_speed, int time)
{
	this->name = s_name, this->speed = s_speed, this->time_before_rest = time;
}
double All_terrain_boots::travel_time(int distance)
{
	double x, t;
	t = distance / get_Speed(); // ����� � ����
	x = static_cast<int>(t / get_time_before_rest()); // ���������� ��������� � ����
	if (x < 1) { return t; }
	if (x == 1) { return t + 10; }    // ������������ ������� � �������
	else if (x > 1) { return (t + 5 * x); }
	else return 0;
}