#include "../h_files/Rectangle.h"
Rectangle::Rectangle(int a, int b)
    {
        name = "Прямоугольник"; this->A = this->B = this->C = this->D = 90; this->a = this->c = a; this->b = this->d = b;
    };
Rectangle::Rectangle()
    {
        name = "Прямоугольник"; this->A = this->B = this->C = this->D = 90; this->a = this->c; this->b = this->d;
    };

    bool Rectangle::check()
    {
        return ((get_a() == get_c()) && (get_b() == get_d()) && Quadrangle::check()) ? true : false;
    };