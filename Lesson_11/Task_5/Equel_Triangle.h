#pragma once
#include "Triangle.h"
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif

class BIBLIOTEKA Equel_Triangle :public Triangle
{
public:
    Equel_Triangle(int a);
protected:
    bool check() override;
};

