#include <iostream>
#include <windows.h>
class Counter
{
private:
    int i=1;

public:
    Counter(int i) { this->i = i; }
    Counter() { i = 1; }
    void count_Up ()
    {
        this->i = ++this->i;
    }
    void count_Down ()
    {
        this->i = --this->i;
    }
    void print ()
    {
        std::cout << this->i << std::endl;
    }    
};
int main()
{   
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    std::string s;
    int x=1;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> s;
    if (s == "да") 
    { 
        std::cout << "Введите начальное значение счётчика: "; 
        std::cin >> x;       
    }   
    Counter count(x);
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