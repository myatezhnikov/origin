#pragma once
#include "Triangle.h"
class Equel_Triangle :public Triangle
{
public:
    Equel_Triangle(int a);
protected:
    bool check() override;
};

