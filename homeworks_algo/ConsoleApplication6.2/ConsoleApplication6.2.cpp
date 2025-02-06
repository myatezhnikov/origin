#include <iostream>
#include <cmath>
bool test(int& p) 
{    //проверка, является ли число простым
    if (p <= 1) return false;
    for (int i = 2; i * i <= p; ++i) 
    {
        if (p % i == 0) { return false; }
    }
    return true; // Если есть остатки от деления значит число простое
}
int real_string_hash(std::string s, int& p, int& n)
{
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {          
        x += char(s[i])*pow(p,i); 
    }
   
    return x % n;
}

int main()
{
    std::string s = "";
    int p = 0, n = 0;
    setlocale(LC_ALL, "Russian");
    do
    {
        std::cout << "Введите р: ";
        std::cin >> p;
        if (test(p)) break;
        else std::cout << "Это не простое число, введите другое." << std::endl;       
    }   while (true);

    std::cout << "Введите n: ";
    std::cin >> n;

    do
    {
        std::cout << "Введите строку: ";
        std::cin >> s; 
        std::cout << "Хэш строки " << s << " = " << real_string_hash(s,p,n);
        std::cout << std::endl;
    } while (s != "exit");
    
    system("Pause");
}