#include "Transport.h"
Transport::Transport() { }
Transport::~Transport() { }

double Transport::get_Speed() { return speed; } 
std::string Transport::get_Type_Transport() { return type_transport; }
std::string Transport::get_Name() { return name; }
double Transport::travel_time(int distance) { return 0; };