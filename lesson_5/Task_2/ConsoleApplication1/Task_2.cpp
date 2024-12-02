#include <iostream>
class Figure
{
public:
    Figure() {};  
    std::string get_name() { return name; };
    int get_sides_count() { return sides_count; };
virtual void print() { };
protected:
    int sides_count = 0;
    std::string name = "Фигура";
};
class Triangle : public Figure
{
protected: 
    int a = 10, b = 20, c = 30;
    int A = 50, B = 60, C = 70;
    //int a, b, c, d, A, B, C, D;
public:
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    Triangle(int a, int b, int c, int A, int B, int C)
    {
        sides_count = 3; name = "Треугольник"; this->a = a; this->b = b; this->c = c; this->A = A; this->B = B; this->C = C;
    };
    Triangle() { sides_count = 3; name = "Треугольник"; };
protected:
    void print()
    {
        std::cout << get_name() << ": " << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
        std::cout << std::endl;
    };   
};
class Right_Triangle : public Triangle
{
public:
    Right_Triangle(int a, int b, int c, int A, int B)
    {
        name = "Прямоугольный треугольник"; this->a = a; this->b = b; this->c = c; this->A = A; this->B = B; this->C = 90;
    };
};
class Iso_Triangle :public Triangle
{
public:
    Iso_Triangle(int a, int b, int A,int B) 
    {
        name = "Равнобедренный треугольник"; this->c = this->a = a; this->b = b; this->C = this->A = A; this->B = B;
    };
};
class Equel_Triangle :public Triangle
{
public:
    Equel_Triangle(int a)
    {
        name = "Равносторонний треугольник"; this->b = this->a = this->c = a; this->A = this->B = this->C = 60;
    };
};
   
class Quadrangle : public Figure
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 50, B = 60, C = 70, D = 80;
   // int a, b, c, d, A, B, C, D;
public:
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }  
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    { 
        sides_count = 4; name = "Четырёхугольник"; this->a = a; this->b = b; this->c = c; this->d = d; this->A = A; this->B = B; this->C = C; this->D = D;
    };
    Quadrangle() { sides_count = 4; name = "Четырёхугольник"; };
private:
    void print() 
    {
        std::cout << get_name() << ": " << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;    
        std::cout << std::endl;
    };
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B)
    {
        name = "Параллелограмм"; this->c = this->a = a; this->d = this->b = b; this->C = this->A = A; this->D = this->B = B;
    };
    Parallelogram()
    {
        name = "Параллелограмм"; this->c = this->a; this->d = this->b; this->C = this->A; this->D = this->B;
    };
};
class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b) 
    {
        name = "Прямоугольник"; this->A = this->B = this->C = this->D = 90; this->a = this->c = a; this->b = this->d = b;
    };  
};
class Romb : public Parallelogram
{
public:
    Romb(int a, int A, int B)
    {
        name = "Ромб"; this->b = this->a = this->d = this->c = a; this->A = this->C = A; this->B = this->D = B;
    };
    Romb()
    {
        name = "Ромб"; this->b = this->a = this->d = this->c; this->A = this->C; this->B = this->D;
    };
};
class Square : public Romb
{
public:   
    Square(int a) 
    { 
        name = "Квадрат"; this->A = this->C = this->B = this->D = 90; this->c = this->a = a; this->d = this->b = a; 
    }
};
  
void print_info(Figure* f) 
{ 
    f->print(); 
};

int main()   
{
    setlocale(LC_ALL, "Russian");
   
    Triangle t(10,20,30,50,60,70);
    Right_Triangle rt(10,20,30,50,60);
    Iso_Triangle it(10,20,50,60);
    Equel_Triangle eq(10);
    Quadrangle q(10,20,30,40,50,60,70,80);
    Rectangle r(10,20);
    Square s(10);
    Parallelogram p(10,20,50,60);
    Romb rmb(10,50,60);
    print_info(&t);
    print_info(&rt);
    print_info(&it);
    print_info(&eq);
    print_info(&q);
    print_info(&r);
    print_info(&s);
    print_info(&p);
    print_info(&rmb);
};
