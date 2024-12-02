#include <iostream>
class Figure
{
public:
    Figure() {};
   
    virtual void print_info()
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
        std::cout << std::endl;
    };
protected:
    std::string get_name() { return name; };
    int get_sides_count() { return sides_count; };
    int sides_count = 0;
    std::string name = "Фигура";
    virtual bool check()
    {
        return !static_cast<bool>(this->get_sides_count());
    };
};
class Triangle : public Figure
{
protected:
    int a = 10, b = 20, c = 30;
    int A = 50, B = 60, C = 70;
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    virtual bool check() override
    {
        int x = get_A() + get_B() + get_C();
        if ((this->get_sides_count() == 3) && (x == 180)) return true;
        else return false;

    };
public:
    Triangle(int a, int b, int c, int A, int B, int C)
    {
        sides_count = 3; name = "Треугольник"; this->a = a; this->b = b; this->c = c; this->A = A; this->B = B; this->C = C;
    };
    Triangle() { sides_count = 3; name = "Треугольник"; };
protected:
    void print_info() override
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
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
protected:
    bool check() override
    {
        return (get_C() == 90 && Triangle::check()) ? true : false;
    };
};
class Iso_Triangle :public Triangle
{
public:
    Iso_Triangle(int a, int b, int A, int B)
    {
        name = "Равнобедренный треугольник"; this->c = this->a = a; this->b = b; this->C = this->A = A; this->B = B;
    };
protected:
    bool check() override
    {
        return (get_C() == get_A() && get_c() == get_a() && Triangle::check()) ? true : false;
    };
};
class Equel_Triangle :public Triangle
{
public:
    Equel_Triangle(int a)
    {
        name = "Равносторонний треугольник"; this->b = this->a = this->c = a; this->A = this->B = this->C = 60;
    }
protected:
    bool check() override
    {
        return (get_c() == get_a() && get_a() == get_b() && Triangle::check()) ? true : false;
    };
};

class Quadrangle : public Figure
{
protected:
    int a = 10, b = 20, c = 30, d = 40;
    int A = 50, B = 60, C = 70, D = 80;
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        sides_count = 4; name = "Четырёхугольник"; this->a = a; this->b = b; this->c = c; this->d = d; this->A = A; this->B = B; this->C = C; this->D = D;
    };
    Quadrangle() { sides_count = 4; name = "Четырёхугольник"; };
protected:
    void print_info() override
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
        std::cout << std::endl;
    };
//protected:
     bool check() override
    {
        int x = get_A() + get_B() + get_C() + get_D();
        if ((this->get_sides_count() == 4) && (x == 360)) return true;
        else return false;
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
protected:
    bool check() override
    {
        return (Quadrangle::check() && get_A() == get_C() && get_B() == get_D()) ? true : false;
    };
};
class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b)
    {
        name = "Прямоугольник"; this->A = this->B = this->C = this->D = 90; this->a = this->c = a; this->b = this->d = b;
    };
    Rectangle()
    {
        name = "Прямоугольник"; this->A = this->B = this->C = this->D = 90; this->a = this->c; this->b = this->d;
    };
protected:
    bool check() override
    {
        return ((get_a() == get_c()) && (get_b() == get_d()) && Quadrangle::check()) ? true : false;
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
protected:
    bool check() override
    {
        return (Parallelogram::check() && get_a() == get_b() == get_c() == get_d()) ? true : false;
    };

};
class Square : public Rectangle
{
public:
    Square(int a)
    {
        name = "Квадрат"; this->A = this->C = this->B = this->D = 90; this->c = this->a = this->d = this->b = a;
    }
protected:
    virtual bool check() override
    {
        return (get_c() == get_b() && Rectangle::check()) ? true : false;
    };
};

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
};
