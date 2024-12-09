#include "../h_files/Triangle.h"

    //int a = 10, b = 20, c = 30;
   // int A = 50, B = 60, C = 70;
    int Triangle::get_a() { return a; }
    int Triangle::get_b() { return b; }
    int Triangle::get_c() { return c; }
    int Triangle::get_A() { return A; }
    int Triangle::get_B() { return B; }
    int Triangle::get_C() { return C; }
    bool Triangle::check()
    {
        int x = get_A() + get_B() + get_C();
        if ((this->get_sides_count() == 3) && (x == 180)) return true;
        else return false;

    };

    Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    {
        sides_count = 3; name = "Треугольник"; this->a = a; this->b = b; this->c = c; this->A = A; this->B = B; this->C = C;
    };
    Triangle::Triangle() { sides_count = 3; name = "Треугольник"; };

    void Triangle::print_info()
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
        std::cout << std::endl;
    };
