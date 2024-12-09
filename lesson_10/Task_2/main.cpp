//#include <iostream>
#include "h_files/Figure.h"
#include "h_files/Iso_Triangle.h"
#include "h_files/Right_Triangle.h"
#include "h_files/Equel_Triangle.h"
#include "h_files/Romb.h"
#include "h_files/Square.h"

void print_info(Figure* f)
{
    f->print_info();
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Figure f;
    Triangle t(10, 20, 30, 50, 60, 70);
    Right_Triangle rt(10, 20, 30, 50, 60);
    Iso_Triangle it(10, 20, 50, 60);
    Equel_Triangle eq(10);
    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle r(10, 20);
    Square s(20);
    Parallelogram p(20, 30, 30, 40);
    Romb rmb(30, 30, 40);
    print_info(&f);
    print_info(&t);
    print_info(&rt);
    print_info(&it);
    print_info(&eq);
    print_info(&q);
    print_info(&r);
    print_info(&s);
    print_info(&p);
    print_info(&rmb);
    system("pause");
};
