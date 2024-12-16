#pragma once
#include "Triangle.h"
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif

class BIBLIOTEKA Iso_Triangle :public Triangle
{
public:
    Iso_Triangle(int a, int b, int A, int B);
protected:
    bool check() override;
};
