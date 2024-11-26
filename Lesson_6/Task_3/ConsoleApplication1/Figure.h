#pragma once
#include<string>
class Figure
{
public:
    Figure();                       // конструктор и методы всех фигур
    int get_a();
    int get_b();
    int get_c();
    int get_d();
    int get_A();
    int get_B();
    int get_C();
    int get_D();
    std::string get_name();
protected:
    std::string name = "Фигура";
    int a = 0, b = 0, c = 0, d = 0;
    int A = 0, B = 0, C = 0, D = 0;
};

