#include "Romb.h"
Romb::Romb(int a, int A, int B)
    {
        name = "����"; this->b = this->a = this->d = this->c = a; this->A = this->C = A; this->B = this->D = B;
        Quadrangle::check();
        Quadrangle::print_creation();
    };
Romb::Romb()
    {
        name = "����"; this->b = this->a = this->d = this->c; this->A = this->C; this->B = this->D;
        Quadrangle::check();
        Quadrangle::print_creation();
    };
    bool Romb::check()
    {
        return (Parallelogram::check() && get_a() == get_b() == get_c() == get_d()) ? true : false;
    };