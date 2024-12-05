#include <string>
#include <iostream>
class bad_length : public std::exception
{
public:
    const char* what() const override
    {
        return "Вы ввели слово запретной длины! До свидания";
    };
};

int function(std::string str, int forbidden_length)
{
    if (str.length() != forbidden_length) { return str.length(); }
    else throw bad_length();
};

int l{ 0 };
std::string s{ "" };
bool out{ 1 };
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите запретную длину ";
    std::cin >> l;
        do
        {
            try {
                std::cout << "Введите слово: ";
                std::cin >> s;
                std::cout << "Длина слова " << s << " равна " << function(s, l) << std::endl;
            }
             catch (const bad_length& bad)
             {
                 std::cout << bad.what() << std::endl; out = false;
             }  
        } while (out);
}