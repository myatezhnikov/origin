#pragma once
#include "Quadrangle.h"
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif

class BIBLIOTEKA Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B);
    Parallelogram();
protected:
    bool check() override;
};
