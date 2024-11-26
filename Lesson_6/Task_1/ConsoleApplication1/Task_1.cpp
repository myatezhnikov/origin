#include <iostream>
#include"Math1.h"

int main()
{
    double a = 0, b = 0;
    int x=10;
    bool exit{0};
    setlocale(LC_ALL, "Russian");
    while (!exit)
    {
        std::cout << "Введите первое число : ";
        std::cin >> a;
        std::cout << "Введите второе число : ";
        std::cin >> b;
        std::cout << "Выберите операцию(0 - выход, 1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень) : ";
        std::cin >> x;
        switch (x)
        {
        case 0: exit = true; break;
        case 1: std::cout << a << " + " << b << " = " << sum(a, b); break;
        case 2: std::cout << a << " + " << b << " = " << diff(a, b); break;
        case 3: std::cout << a << " + " << b << " = " << multiplication(a, b); break;
        case 4: std::cout << a << " + " << b << " = " << division(a, b); break;
        case 5: std::cout << a << " в степени " << static_cast<int>(b) << " = " << exponenta(a, b); break;
        };
        std::cout << std::endl;
    };
}


