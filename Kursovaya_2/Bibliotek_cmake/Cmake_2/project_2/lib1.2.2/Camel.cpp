#include"Camel.h"
#include<iostream>

Camel::Camel()
{
	name = "�������"; speed = 10; time_before_rest = 30; //���, ��������, ����� �������� �� ������
}
Camel::Camel(std::string s_name, int s_speed, int time)
{
	name = s_name, speed = s_speed, time_before_rest = time;
}

Camel::~Camel()
{
}
double Camel::travel_time(int distance) //������ ���: 5 ��� ����������� ���� : 8
{
	double x{ 0 }, t{ 0 };
	t = distance / get_Speed(); // ����� � ����
	x = t / get_time_before_rest(); // ���������� ��������� � ����
	if (x == (int)x) { x = x - 1; } //���������, ���� ��������� ��������� �������� �� �����, �� ��������� ���-�� �������� ��������� �� 1
	x = static_cast<int>(x);
	if (x < 1) { return t; }
	if (x == 1) { return t + 5; }
	else if (x > 1) { return (t + 5 + 8 * (x-1)); }
	else return 0;
}