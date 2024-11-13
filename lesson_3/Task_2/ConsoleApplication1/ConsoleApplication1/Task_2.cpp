#include <iostream>
class Counter
{
private:
    int i=1;

public:
    Counter (int i) {}
    Counter() { i = 1; }
    void count_Up ()
    {
        i = i++;
    }
    void count_Down ()
    {
        i = i--;
    }
    void print ()
    {
        std::cout << i << std::endl;
    }
    
};
int main()
{   
    setlocale(LC_ALL, "Russian");
    std::string s;
   // Counter count;
    int x=1;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> s; std::cout << "\n" << s;
    if (s == "да") 
    { 
        std::cout << "Введите начальное значение счётчика: "; 
        std::cin >> x; 
       // Counter count(x);
    }
    else if (s == "нет") {
        x = 1; 
       // Counter count;
    }
    Counter count(x);
    char command;
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command; std::cout << command << std::endl;
        switch (command)
        {
        case 43: count.print();  break;
        case 45: break;
        case 61: count.print(); break;
        }
    } while (command == 120);
         
}