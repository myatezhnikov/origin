#pragma once
#include "Figure.h"
class Triangle :
    public Figure
{   
    protected:
        int a = 10, b = 20, c = 30;
        int A = 50, B = 60, C = 70;
        int get_a();
        int get_b();
        int get_c();
        int get_A();
        int get_B();
        int get_C();
        virtual bool check() override;
    public:
        Triangle(int a, int b, int c, int A, int B, int C);
        Triangle();
    protected:
        void print_info() override;
        void print_creation() override;
    };