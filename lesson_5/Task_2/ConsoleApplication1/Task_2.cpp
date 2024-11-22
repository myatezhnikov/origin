#include <iostream>
class Figure
{
public:
    Figure() {};                        // конструктор и методы всех фигур
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }
    std::string get_name() { return name; };
protected:
   
    std::string name = "Фигура";
    int a = 0, b = 0, c = 0, d = 0; // у нулевой фигуры стороны равны нулю
    int A = 0, B = 0, C = 0, D = 0; // у нулевой фигуры углы равны нулю
};
class Triangle : public Figure
{
public:                                                     // Разные конструкторы треугольников
    Triangle(int a, int b, int c, int A, int B, int C)
    {
        name = "Треугольник"; this->a = 10; this->b = 20; this->c = 30; this->A = 50; this->B = 60; this->C = 70;
    };
    Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C)
    {
        name = "Прямоугольный треугольник"; this->C = 90;
    };
    Triangle(int a, int b, int A, int B) : Triangle(a, b, c, A, B, C)
    {
        name = "Равнобедренный треугольник"; this->c = this->a; this->C = this->A;
    };
    Triangle(int a) : Triangle(a, b, c, A, B, C)
    {
        name = "Равносторонний треугольник"; this->b = this->c = this->a; this->A = this->B = this->C = 60; 
    };
    Triangle() {};
};
class Quadrangle : public Figure
{
public:                                                                  // Разные конструкторы четырехугольников
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        name = "Четырёхугольник"; this->a = 10; this->b = 20; this->c = 30; this->d = 40; this->A = 50; this->B = 60; this->C = 70; this->D = 80;
    };
    Quadrangle(int a, int b) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Прямоугольник"; this->c = this->a; this->d = this->b; this->A = this->B = this->C = this->D = 90;
    };
    Quadrangle(int a) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Квадрат"; this->b = this->c = this->d = this->a; this->A = this->B = this->C = this->D = 90;
    };
    Quadrangle(int a, int b, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Параллелограмм"; this->c = this->a; this->d = this->b; this->C = this->A; this->D = this->B;
    };
    Quadrangle(int a, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        name = "Ромб"; this->b = this->c = this-> d = this->a; this->C = this->A; this->D = this->B;
    };
    Quadrangle() {};
};
void print_info(Figure *f) // вывод на экран разных фигур
{   
    std::cout <<f->get_name() << ": " << std::endl;
    std::cout << "Стороны: a=" << f->get_a() << " b=" << f->get_b() << " c=" << f->get_c(); 
    if (f->get_d() != 0) { std::cout << " d=" << f->get_d(); }      // если 4-й параметр ненулевой значит прямоугольник
    std::cout<< std::endl;
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
