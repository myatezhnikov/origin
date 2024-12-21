#include "Centaur.h"
Centaur::Centaur()
{
	name = "�������"; speed = 15; time_before_rest = 8; //���, ��������, ����� �������� �� ������
}
Centaur::Centaur(std::string s_name, int s_speed, int time)
{
	this->name = s_name, this->speed = s_speed, this->time_before_rest = time;
}
double Centaur::travel_time(int distance)
{
	double x, t;
	t = distance / get_Speed(); // ����� � ���� ��� ���������
	x = t / get_time_before_rest(); // ���������� ��������� � ����
	if (x == (int)x) { x = x - 1; } //���������, ���� ��������� ��������� �������� �� �����, �� ��������� ���-�� �������� ��������� �� 1
	x = static_cast<int>(x);
	if (x > 0) { return t + 2*x; }
	else return 0;
}