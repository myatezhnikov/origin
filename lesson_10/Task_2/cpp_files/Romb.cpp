#include "../h_files/Romb.h"
Romb::Romb(int a, int A, int B)
    {
        name = "Ромб"; this->b = this->a = this->d = this->c = a; this->A = this->C = A; this->B = this->D = B;
    };
Romb::Romb()
    {
        name = "Ромб"; this->b = this->a = this->d = this->c; this->A = this->C; this->B = this->D;
    };
    bool Romb::check()
    {
        return (Parallelogram::check() && get_a() == get_b() == get_c() == get_d()) ? true : false;
    };