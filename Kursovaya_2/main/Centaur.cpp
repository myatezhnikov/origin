#include "Centaur.h"
Centaur::Centaur()
{
	name = "Кентавр"; speed = 15; time_before_rest = 5; //Имя, скорость, время движения до отдыха
}
Centaur::Centaur(std::string s_name, int s_speed, int time)
{
	this->name = s_name, this->speed = s_speed, this->time_before_rest = time;
}
double Centaur::travel_time(int distance)
{
	double x, t;
	t = distance / get_Speed(); // время в пути
	x = static_cast<int>(t / get_time_before_rest()); // количество остановок в пути
	if (x > 0) { return t + 2; }
	else return 0;
}