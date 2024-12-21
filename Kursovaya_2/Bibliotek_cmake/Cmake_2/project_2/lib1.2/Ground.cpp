#include"Ground.h"
#include"Transport.h"

Ground::Ground()
{
	this->type_transport = "Ground";
};
Ground::~Ground()
{
}
double Ground::get_time_before_rest() { return time_before_rest; }