#include <iostream>
#include <windows.h>
#include "Counter.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    std::string s;

    int x;
    Counter count;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> s;
    if (s == "да")
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> x;
        Counter c(x); //Временный счетчик с параметрами
        count = c;
    }

    char command;
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
        switch (command)
        {
        case 43: count.count_Up(); break;
        case 45: count.count_Down(); break;
        case 61: count.print(); break;
        }
    } while (command != 120);
    std::cout << "До свидания!" << std::endl;
}