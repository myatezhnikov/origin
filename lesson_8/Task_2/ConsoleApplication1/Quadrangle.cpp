#include "Quadrangle.h"
#include "Errors.h"
  
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
            sides_count = 4; name = "��������������"; this->a = a; this->b = b; this->c = c; this->d = d; this->A = A; this->B = B; this->C = C; this->D = D;
            check();
            print_creation();       
     };
    Quadrangle::Quadrangle() { sides_count = 4; name = "��������������"; };

    void Quadrangle::print_info()
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << (this->check() ? "����������" : "������������") << std::endl;
        std::cout << "���������� ������: " << this->get_sides_count() << std::endl;
        std::cout << "�������: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "����: �=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
        std::cout << std::endl;
    };
    bool Quadrangle::check() 
    {
      
        if ((a != 0) && (b != 0) && (c != 0) && (d !=0)) //��������� �� ������� �������� ������
        {       
           
            if ((A + B + C + D) == 360) return true;  //��������� �� ����� �����
            else throw Errors("����� ����� �� ����� 360");
        }
        else throw Errors("������� ����� 0");
    };
    void Quadrangle::print_creation()
    {
        std::cout << this->get_name() << " (������� " << get_a() << ", " << get_b() << ", " << get_c() << ", " << get_d();
        std::cout << "; ���� " << get_A() << ", " << get_B() << ", " << get_C() << ", " << get_D() << ") ������" << std::endl;
    };