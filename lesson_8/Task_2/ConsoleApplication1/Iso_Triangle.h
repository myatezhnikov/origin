#pragma once
#include "Triangle.h"
class Iso_Triangle :public Triangle
{
public:
    Iso_Triangle(int a, int b, int A, int B);
protected:
    bool check() override;
};
