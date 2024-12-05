#include <iostream>
#include "Errors.h"
#include "Figure.h"
#include "Iso_Triangle.h"
#include "Right_Triangle.h"
#include "Equel_Triangle.h"
#include "Romb.h"
#include "Square.h"

void print_info(Figure* f)
{
    f->print_info();
};

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        Figure f;
        Triangle t(10, 20, 30, 70, 60, 50);
        Right_Triangle rt(10, 20, 30, 30, 60);
        Iso_Triangle it(10, 20, 50, 80);
        Equel_Triangle eq(10);       
        Quadrangle q(10, 20, 30, 40, 80, 110, 70, 100);
        Parallelogram p(20, 30, 100, 80);
        Rectangle r(20,30);
        Square s(80);        
        Romb rmb(30, 90, 90);     
      
    }
    catch (const Errors & err)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << err.what() << std::endl;
    }
};
