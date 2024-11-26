#include "Triangle.h"

                                                     // Разные конструкторы треугольников
Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    {
        name = "Треугольник"; this->a = 10; this->b = 20; this->c = 30; this->A = 50; this->B = 60; this->C = 70;
    };
Triangle::Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C)
    {
        name = "Прямоугольный треугольник"; this->C = 90;
    };
Triangle::Triangle(int a, int b, int A, int B) : Triangle(a, b, c, A, B, C)
    {
        name = "Равнобедренный треугольник"; this->c = this->a; this->C = this->A;
    };
Triangle::Triangle(int a) : Triangle(a, b, c, A, B, C)
    {
        name = "Равносторонний треугольник"; this->b = this->c = this->a; this->A = this->B = this->C = 60;
    };
Triangle::Triangle() {};