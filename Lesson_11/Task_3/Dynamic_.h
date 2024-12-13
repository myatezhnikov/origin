#pragma once
#include <string>
#include <iostream>
#ifdef BIBLIOTEKI_EXPORTS
#define BIBLIOTEKI __declspec(dllexport)
#else
#define BIBLIOTEKI __declspec(dllimport)
#endif

class BIBLIOTEKI Leaver
{
public:
	Leaver();
	std::string leave(std::string s);
	
};