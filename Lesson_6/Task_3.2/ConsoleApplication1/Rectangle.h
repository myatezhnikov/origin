#pragma once
#include "Parallelogram.h"
class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b);
    Rectangle();
protected:
    bool check() override;
};

