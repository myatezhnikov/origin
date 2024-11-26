#pragma once
#include "Figure.h"
class Quadrangle :
    public Figure
{
public:                                                                  // Разные конструкторы четырехугольников
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
    Quadrangle(int a, int b); 
    Quadrangle(int a);
    Quadrangle(int a, int b, int A, int B);
    Quadrangle(int a, int A, int B);
    Quadrangle();
};

