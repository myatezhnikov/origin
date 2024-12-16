#include"Camel.h"
#include<iostream>
#include"Transport.h"

Camel::Camel()
{
	name = "Верблюд"; speed = 10; time_before_rest = 30; //Имя, скорость, время движения до отдыха
}
Camel::Camel(std::string s_name, int s_speed, int time)
{
	name = s_name, speed = s_speed, time_before_rest = time;
}

Camel::~Camel()
{
}
double Camel::travel_time(int distance) //Первый раз: 5 Все последующие разы : 8
{
	double x{ 0 }, t{ 0 };
	t = distance / get_Speed(); // время в пути
	x = static_cast<int>(t / get_time_before_rest()); // количество остановок в пути
	if (x < 1) { return t; }
	if (x == 1) { return t + 5; }
	else if (x > 1) { return (t + 8 * x); }
	else return 0;
}