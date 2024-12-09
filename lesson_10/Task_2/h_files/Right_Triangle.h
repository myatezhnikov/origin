#pragma once
#include "Triangle.h"
class Right_Triangle :
    public Triangle
{
public:
    Right_Triangle(int a, int b, int c, int A, int B);
protected:
    bool check() override;
};

