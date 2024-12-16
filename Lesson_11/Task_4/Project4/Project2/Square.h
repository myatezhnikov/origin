#pragma once
#include "Rectangle.h"
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif

class BIBLIOTEKA Square : public Rectangle
{
public:
    Square(int a);
protected:
    virtual bool check() override;
};

