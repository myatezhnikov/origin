#pragma once
#include<string>

class Transport  // ������� ����� (�������)
{
public:
	Transport();
	~Transport();

	std::string get_Name();
	std::string get_Type_Transport();
	virtual double travel_time(int distance); //����� ����������� �� �����. ������� ������� �������
	double get_Speed();

protected:
	double speed{ 0 };
	std::string name{ "" };
	std::string type_transport{ "" };
	
	
};

