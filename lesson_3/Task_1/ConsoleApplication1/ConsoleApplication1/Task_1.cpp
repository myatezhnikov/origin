#include <iostream>
class calculator {
public:
    double num1, num2;
    double add()
    {
        return this->num1 + this->num2;
    }
    double multiply()
    { 
        return this->num1 * this->num2; 
    }
    double subtract_1_2()
    { 
        return this->num1 - this->num2; 
    }
    double subtract_2_1()
    {
        return this->num2 - this->num1;
    }
    double divide_1_2()
    {
        return this->num1 / num2;
    }
    double divide_2_1()
    {
        return this->num2 / num1;
    }
    bool set_num1(double num1)
    {       
        if (num1 != 0) 
        { 
            this->num1 = num1; return true; 
        }
        return false;
    }
    bool set_num2(double num2)
    {
        if (num2 != 0) 
        {
            this->num2 = num2; return true; 
        }
        return false;
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    double x;
    calculator c;
    while (true) 
    {
        do
        {
            std::cout << "Введите num1: ";
            std::cin >> x; 
            if (c.set_num1(x)) break;
            else {
                std::cout << "Неправльиный ввод!\n";
            }
        } while (true);
        do
        {
            std::cout << "Введите num2: ";
            std::cin >> x;
            if (c.set_num2(x)) break;
            else {
                std::cout << "Неправльиный ввод!\n";
            }
        } while (true);
       
        std::cout << "num1 + num2 = " << c.add() << "\n";
        std::cout << "num1 - num2 = " << c.subtract_1_2() << "\n";
        std::cout << "num2 - num1 = " << c.subtract_2_1() << "\n";
        std::cout << "num1 * num2 = " << c.multiply() << "\n";
        std::cout << "num1 / num2 = " << c.divide_1_2() << "\n";
        std::cout << "num2 / num1 = " << c.divide_2_1() << "\n";
    }
}