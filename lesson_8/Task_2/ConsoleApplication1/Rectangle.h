#pragma once
#include "Parallelogram.h"
class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b);
   
protected:
    bool check() override;
    Rectangle();
};

