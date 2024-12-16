#pragma once
#include "Parallelogram.h"
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif


class BIBLIOTEKA Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b);
    Rectangle();
protected:
    bool check() override;
};

