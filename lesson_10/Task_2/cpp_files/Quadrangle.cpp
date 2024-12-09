#include "../h_files/Quadrangle.h"
   // int a = 10, b = 20, c = 30, d = 40;
   // int A = 50, B = 60, C = 70, D = 80;
    int Quadrangle::get_a() { return a; }
    int Quadrangle::get_b() { return b; }
    int Quadrangle::get_c() { return c; }
    int Quadrangle::get_d() { return d; }
    int Quadrangle::get_A() { return A; }
    int Quadrangle::get_B() { return B; }
    int Quadrangle::get_C() { return C; }
    int Quadrangle::get_D() { return D; }
    Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        sides_count = 4; name = "Четырёхугольник"; this->a = a; this->b = b; this->c = c; this->d = d; this->A = A; this->B = B; this->C = C; this->D = D;
    };
    Quadrangle::Quadrangle() { sides_count = 4; name = "Четырёхугольник"; };

    void Quadrangle::print_info()
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
        std::cout << std::endl;
    };
    bool Quadrangle::check() 
    {
        int x = get_A() + get_B() + get_C() + get_D();
        if ((this->get_sides_count() == 4) && (x == 360)) return true;
        else return false;
    };