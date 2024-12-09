#include "../h_files/Equel_Triangle.h"
Equel_Triangle::Equel_Triangle(int a)
    {
        name = "Равносторонний треугольник"; this->b = this->a = this->c = a; this->A = this->B = this->C = 60;
    }
    bool Equel_Triangle::check()
    {
        return (get_c() == get_a() && get_a() == get_b() && Triangle::check()) ? true : false;
    };