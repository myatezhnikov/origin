#include "../h_files/Iso_Triangle.h"
Iso_Triangle::Iso_Triangle(int a, int b, int A, int B)
    {
        name = "Равнобедренный треугольник"; this->c = this->a = a; this->b = b; this->C = this->A = A; this->B = B;
    };
    bool Iso_Triangle::check()
    {
        return (get_C() == get_A() && get_c() == get_a() && Triangle::check()) ? true : false;
    };