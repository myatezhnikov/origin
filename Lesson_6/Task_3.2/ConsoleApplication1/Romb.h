#pragma once
#include "Parallelogram.h"
class Romb : public Parallelogram
{
public:
    Romb(int a, int A, int B);
    Romb();
protected:
    bool check() override;

};
