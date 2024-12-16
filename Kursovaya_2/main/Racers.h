#pragma once
#include<string>
using namespace std;
class Racers // Вспомогательный класс участников гонки
{
public:
	Racers(string s_name, double s_travel_time);
	Racers();
	double get_Time();
	string get_Name();
	void set_racer(string s_name, double s_travel_time);
protected:
	string name{ "" }; double travel_time = 0;  // поля имя и время в пути гонщика

};