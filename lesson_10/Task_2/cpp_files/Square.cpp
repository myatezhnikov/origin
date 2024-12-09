#include "../h_files/Square.h"
Square::Square(int a)
    {
        name = " вадрат"; this->A = this->C = this->B = this->D = 90; this->c = this->a = this->d = this->b = a;
    }
    bool Square::check()
    {
        return (get_c() == get_b() && Rectangle::check()) ? true : false;
    };