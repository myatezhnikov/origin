#pragma once
#include "Parallelogram.h"
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif

class BIBLIOTEKA Romb : public Parallelogram
{
public:
    Romb(int a, int A, int B);
    Romb();
protected:
    bool check() override;

};
