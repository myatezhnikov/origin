#pragma once
#include "Rectangle.h"
class Square : public Rectangle
{
public:
    Square(int a);
protected:
    virtual bool check() override;
};

