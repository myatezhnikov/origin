#include <iostream>

class Figure
{
protected:
    int sides_count = 0;
    std::string name = "Фигура";
    std::string get_name() { return name; };
    int get_sides_count() { return sides_count; };
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

    virtual bool check()
    {
        return !static_cast<bool>(this->get_sides_count());
    };
public:
    Figure() {};      
   virtual void print_info()
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
        std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
        if (this->get_sides_count() > 0)
        {
            std::cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c;
            if (this->get_sides_count() == 4) { std::cout << " d=" << this->d; }
            std::cout << std::endl;
            std::cout << "Углы: A=" << this->A << " B=" << this->B << " C=" << this->C;
            if (this->get_sides_count() == 4) { std::cout << " D=" << this->D; }
            std::cout << std::endl;            
        };
        std::cout << std::endl;
    };
};

class Triangle : public Figure
{
protected:   
   virtual bool check() override
    {
        int x = get_A() + get_B() + get_C();
        if ((this->get_sides_count() == 3) && (x == 180)) return true;
        else return false;
        
    };
public:         
    Triangle()
    {
        this->name = "Треугольник"; this->sides_count = 3;
    };  
};

class Right_Triangle : public Triangle
{
public:
    Right_Triangle()
    {
        name = "Прямоугольный треугольник"; this->C = 90;
    };
protected:
    bool check() override
    {       
        return (get_C() == 90 && Triangle::check()) ? true : false;      
    };
};

class Iso_Triangle : public Triangle
{
public:
    Iso_Triangle()
    {
        name = "Равнобедренный треугольник"; this->c = this->a; this->C = this->A;
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
    Equel_Triangle()
    {
        name = "Равносторонний треугольник"; this->b = this->a = this->c; this->A = this->B = this->C = 60;
    };
protected:
    bool check() override
    {
        return (get_c() == get_a() && get_a() == get_b() && Triangle::check()) ? true : false;
    };
};

class Quadrangle : public Figure
{
public:
    Quadrangle()
    {
        name = "Четырёхугольник"; sides_count = 4; 
    }
protected:
    virtual bool check() override
    {
        int x = get_A() + get_B() + get_C() + get_D();
        if ((this->get_sides_count() == 4) && (x == 360)) return true;
        else return false;
    };  
};

class Rectangle : public Quadrangle
{
public:
    Rectangle()
    {
        name = "Прямоугольник"; this->c = this->a; this->d = this->b; this->A = this->B = this->C = this->D = 90;
    }
protected:
    virtual bool check() override
    {       
        return ((get_a() == get_c()) && (get_b() == get_d()) && Quadrangle::check()) ? true : false;       
    };
};
class Square : public Rectangle
{
public:
    Square()
    {
        name = "Квадрат"; this->a = this->c = this->d = this->b; this->A = this->B = this->C = this->D = 90;
    }
protected:
    virtual bool check() override
    {
        return (get_c() == get_b() && Rectangle::check()) ? true : false;
    };
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram() 
    {
        name = "Параллелограмм"; this->c = this->a; this->b = this->d; this->C = this->A; this->D = this->B;
    }
protected:
    virtual bool check() override
    {
        return (Quadrangle::check() && get_A() == get_C() && get_B() == get_D()) ? true : false;
    };
};
class Romb : public Parallelogram
{
public:
    Romb()
    {
        name = "Ромб"; this->b = this->a = this->d = this->c; this->C = this->A; this->D = this->B;
    }
protected:
    virtual bool check() override
    {
        return (Parallelogram::check() && get_a() == get_b() == get_c() == get_d()) ? true : false;
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Figure f;
    Triangle t;
    Right_Triangle rt;
    Iso_Triangle it;
    Equel_Triangle eq;
    Quadrangle q;
    Rectangle r;
    Square s;
    Parallelogram p;
    Romb rmb;
    f.print_info();
    t.print_info();
    rt.print_info(); 
    it.print_info();
    eq.print_info();
    q.print_info();
    r.print_info();
    s.print_info();
    p.print_info();
    rmb.print_info();
}