#include <iostream>
#define MODE 1

#if MODE == 1 
    int add(int a, int b) { return a + b; };
#endif

int main()
{
    setlocale(LC_ALL, "Russian");
#ifdef MODE
    #if MODE == 1 
        std::cout << "Работаю в боевом режиме" << std::endl;
        int a{ 0 }, b{ 0 };
   
        std::cout << "Введите число 1: ";
        std::cin >> a;
        std::cout << "Введите число 2: ";
        std::cin >> b;
        std::cout << "Результат сложения: " << add(a, b) << std::endl;

    #elif MODE == 0 
        std::cout << "Работаю в режиме тренировки" << std::endl;

    #else   
        std::cout << "Неизвестный режим. Завершение работы\n";
    #endif
#endif

#ifndef MODE 
    #error "Необходиом определить MODE"
#endif


};