#pragma once
#include "Transport.h"
class Ground : public Transport
{
public:
	Ground();
	~Ground();	
protected:
	double time_before_rest{ 0 }; // время движения до остановки в часах
	double get_time_before_rest();
	
};

