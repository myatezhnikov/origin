#include "All_terrain_boots.h"
All_terrain_boots::All_terrain_boots()
{
	name = "Ботинки-вездеходы"; speed = 6; time_before_rest = 60; //Имя, скорость, время движения до отдыха
}
All_terrain_boots::All_terrain_boots(std::string s_name, int s_speed, int time)
{
	this->name = s_name, this->speed = s_speed, this->time_before_rest = time;
}
double All_terrain_boots::travel_time(int distance)
{
	double x, t;
	t = distance / get_Speed(); // время в пути
	x = t / get_time_before_rest(); // количество остановок в пути
	if (x == (int)x) { x = x - 1; } //Проверяем, если последняя остановка выпадает на финиш, то уменьшаем кол-во реальных остановок на 1
	x = static_cast<int>(x);
	if (x < 1) { return t; }
	if (x == 1) { return t + 10; }    // длительность времени с отдыхом
	else if (x > 1) { return (t + 10 + 5 * (x-1)); }
	else return 0;
}