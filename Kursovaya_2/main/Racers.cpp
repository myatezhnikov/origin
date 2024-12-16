#include<string>
#include"Racers.h"
using namespace std;

	Racers::Racers(string s_name, double s_travel_time)
	{
		name = s_name; travel_time = s_travel_time;
	}
	Racers:: Racers() { name = ""; travel_time = 0; }
	double Racers::get_Time() { return travel_time; }
	string Racers::get_Name() { return name; }
	void Racers::set_racer(string s_name, double s_travel_time)
	{
		name = s_name; travel_time = s_travel_time;
		//travel_time = round(s_travel_time * 10 / 10); // округляем
		//travel_time = (int)(s_travel_time * 100 + 0.5) / 100.;
	}