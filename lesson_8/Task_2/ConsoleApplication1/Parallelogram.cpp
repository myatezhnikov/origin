#include "Parallelogram.h"
Parallelogram::Parallelogram(int a, int b, int A, int B)
    {
        name = "ֿאנאככוכמדנאלל"; this->c = this->a = a; this->d = this->b = b; this->C = this->A = A; this->D = this->B = B;
        Quadrangle::check();
        Quadrangle::print_creation();
    };
Parallelogram::Parallelogram()
    {      
       // Quadrangle::check();
    };
    bool Parallelogram::check()
    {
        return (Quadrangle::check() && get_A() == get_C() && get_B() == get_D()) ? true : false;
    };