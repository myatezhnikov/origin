#pragma once
#include "Triangle.h"
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif


class BIBLIOTEKA Right_Triangle :
    public Triangle
{
public:
    Right_Triangle(int a, int b, int c, int A, int B);
protected:
    bool check() override;
};

