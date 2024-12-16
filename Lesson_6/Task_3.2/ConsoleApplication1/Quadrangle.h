#pragma once
#include "Figure.h"
class Quadrangle : public Figure
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 50, B = 60, C = 70, D = 80;
    int get_a();
    int get_b();
    int get_c();
    int get_d();
    int get_A();
    int get_B();
    int get_C();
    int get_D();
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
    Quadrangle();
   
protected:
    void print_info() override;
    bool check() override;
};