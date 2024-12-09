#include "../h_files/Right_Triangle.h"
Right_Triangle::Right_Triangle(int a, int b, int c, int A, int B)
    {
        name = "Прямоугольный треугольник"; this->a = a; this->b = b; this->c = c; this->A = A; this->B = B; this->C = 90;
    };
    bool Right_Triangle::check()
    {
        return (get_C() == 90 && Triangle::check()) ? true : false;
    };