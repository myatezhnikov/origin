#include <iostream>
int simple_string_hash(std::string s)
{
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        x += char(s[i]);
    }
    return x;
}

int main()
{
    std::string s="";
    setlocale(LC_ALL, "Russian");
    do
    {
        std::cout << "Введите строку: ";
        std::cin >> s;
        std::cout << "Наивный хэш строки " << s << " = " << simple_string_hash(s) << std::endl;
    }   while (s != "exit");
    
    system("Pause");
}