#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "Quadrangle.h"

void print_info(Figure* f) // вывод на экран разных фигур
{
    std::cout << f->get_name() << ": " << std::endl;
    std::cout << "Стороны: a=" << f->get_a() << " b=" << f->get_b() << " c=" << f->get_c();
    if (f->get_d() != 0) { std::cout << " d=" << f->get_d(); }      // если 4-й параметр ненулевой значит прямоугольник
    std::cout << std::endl;
    std::cout << "Углы: А=" << f->get_A() << " B=" << f->get_B() << " C=" << f->get_C();
    if (f->get_D() != 0) { std::cout << " D=" << f->get_D(); }  // если 4-й параметр ненулевой значит прямоугольник
    std::cout << std::endl << std::endl;
    return;
};
int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle* t = new Triangle[4];  // создаем массив треугольников пустых
    t[0] = { 1, 2, 3, 4, 5, 6 }; t[1] = { 1, 2, 3, 4, 5 }; t[2] = { 1, 2, 3, 4 }; t[3] = { 1 };  // инициализируем
    for (int i = 0; i < 4; i++) { print_info(&t[i]); }      //выводим на экран
    delete[] t;
    Quadrangle* q = new Quadrangle[5];          // созадем массив прямоугольников пустых
    q[0] = { 1, 2, 3, 4, 5, 6, 7, 8 }; q[1] = { 1, 2 }; q[2] = { 1 }; q[3] = { 1, 2, 3, 4 }; q[4] = { 1, 2, 3 };  // инициализируем
    for (int i = 0; i < 5; i++) { print_info(&q[i]); }          // выводим на экран
    delete[] q;
};