#pragma once
#include "Figure.h"
class Triangle : public Figure
{
public:                                                     // ������ ������������ �������������
    Triangle(int a, int b, int c, int A, int B, int C);
    Triangle(int a, int b, int c, int A, int B); 
    Triangle(int a, int b, int A, int B);
    Triangle(int a);
    Triangle();
};

