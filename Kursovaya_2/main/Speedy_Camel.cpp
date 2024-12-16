#include "Speedy_Camel.h"
Speedy_Camel::Speedy_Camel()
{
	name = "�������-���������"; speed = 40; time_before_rest = 10; //���, ��������, ����� �������� �� ������
}
Speedy_Camel::Speedy_Camel(std::string s_name, int s_speed, int time)
{
	this->name = s_name, this->speed = s_speed, this->time_before_rest = time;
}
double Speedy_Camel::travel_time(int distance)
{
	double x, t;
	t = distance / get_Speed(); // ����� � ����
	x = static_cast<int>(t / get_time_before_rest()); // ���������� ��������� � ����
	if (x < 1) { return t; }
	if (x == 1) { return t + 5; }
	if (x == 2) { return t + 5 + 6.5; }
	else if (x > 2) { return (t + 8 * x); }
	else return 0;
}