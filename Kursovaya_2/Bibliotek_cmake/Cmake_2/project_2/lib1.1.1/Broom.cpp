#include "Broom.h"
#include <iostream>
Broom::Broom()
{
	name = "�����", speed = 20;
}
Broom::Broom(std::string s_name, int s_speed)
{
	name = s_name, speed = s_speed;
}
double Broom::travel_time(int distance)
{
	double t{ 0 }, k{ 0 };
	k = static_cast<int>(distance / 1000); // ����������� ���������� �� ������ 1000 ���� � %
	t = distance / get_Speed(); // ����� � ����
	if (k > 0) { t = (t * (1 - k / 100)); } //���� ������ 1000 �� + %
	return t;
}