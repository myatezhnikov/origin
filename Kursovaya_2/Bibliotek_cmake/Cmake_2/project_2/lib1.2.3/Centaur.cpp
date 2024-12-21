#include "Centaur.h"
Centaur::Centaur()
{
	name = "Кентавр"; speed = 15; time_before_rest = 8; //Имя, скорость, время движения до отдыха
}
Centaur::Centaur(std::string s_name, int s_speed, int time)
{
	this->name = s_name, this->speed = s_speed, this->time_before_rest = time;
}
double Centaur::travel_time(int distance)
{
	double x, t;
	t = distance / get_Speed(); // время в пути без остановок
	x = t / get_time_before_rest(); // количество остановок в пути
	if (x == (int)x) { x = x - 1; } //Проверяем, если последняя остановка выпадает на финиш, то уменьшаем кол-во реальных остановок на 1
	x = static_cast<int>(x);
	if (x > 0) { return t + 2*x; }
	else return 0;
}