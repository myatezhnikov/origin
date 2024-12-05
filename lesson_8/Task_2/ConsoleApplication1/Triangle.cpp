#include "Triangle.h"
#include "Errors.h"
  
    int Triangle::get_a() { return a; }
    int Triangle::get_b() { return b; }
    int Triangle::get_c() { return c; }
    int Triangle::get_A() { return A; }
    int Triangle::get_B() { return B; }
    int Triangle::get_C() { return C; }
    bool Triangle::check()
    {       
        if ((a != 0) && (b != 0) && (c != 0)) //Проверяем на нулевые величины сторон
        {
            if ((A + B + C) == 180) return true;  //Проверяем на сумму углов
            else throw Errors(" Сумма углов не равна 180");
        }
        else throw Errors("Сторона равна 0");
       

    };

    Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    {       
        sides_count = 3; name = "Треугольник"; this->a = a; this->b = b; this->c = c; this->A = A; this->B = B; this->C = C;
        check();
        print_creation();
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
    void Triangle::print_creation()
    {        
            std::cout << this->get_name() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c();
            std::cout << "; углы " << get_A() << ", " << get_B() << ", " << get_C() << ") создан" << std::endl;
    };
