#include "Quadrangle.h"
                                                                // Разные конструкторы четырехугольников
Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        name = "Четырёхугольник"; this->a = 10; this->b = 20; this->c = 30; this->d = 40; this->A = 50; this->B = 60; this->C = 70; this->D = 80;
    };
Quadrangle::Quadrangle(int a, int b) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Прямоугольник"; this->c = this->a; this->d = this->b; this->A = this->B = this->C = this->D = 90;
    };
Quadrangle::Quadrangle(int a) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Квадрат"; this->b = this->c = this->d = this->a; this->A = this->B = this->C = this->D = 90;
    };
Quadrangle::Quadrangle(int a, int b, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Параллелограмм"; this->c = this->a; this->d = this->b; this->C = this->A; this->D = this->B;
    };
Quadrangle::Quadrangle(int a, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Ромб"; this->b = this->c = this->d = this->a; this->C = this->A; this->D = this->B;
    };
Quadrangle::Quadrangle() {};