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

int find_substring_light_rabin_karp(std::string source, std::string substring)
{
    int hashSub = simple_string_hash(substring); // хэш подстроки
    int hash = 0;
    int k = substring.size(); // кол-во символов подстроки
    for (int i = 0; i < (source.size()- (k - 1)); i++) // проверяем ккаждый символ, чтобы проверяемый участок не был больше подстроки
    {
        if (i == 0) { hash = simple_string_hash(source.substr(0, k)); } // если начало то вычисляем хэш первых символов длиною k
        else
        {
            hash -= char(source[i - 1]); // отнимаем предыдущее число символа от суммы
            hash += char(source[i + k - 1]); // прибаляем следующее число к сумме
        } 
        if (hashSub != hash) { continue; }
        else
        {          
            bool test = false;
            for (int j = 0; j < k; j++) // елси хэши совпали, то проверяем каждый символ
            {
                if (source[i + j] != substring[j]) { test=false; break; } // если один символ не тот, то выходим из этого цикла
                else test=true; // если символ равен запоминаем это равенство
            } 
            if (test) return i; else continue; // если все символы были равны то выходим из функции
        }
    }return -1; //если не нашли совпадение
}

int main()
{
    std::string source = "", substring = source;
    int x = 0;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> source;

    do
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> substring;
        x = find_substring_light_rabin_karp(source, substring);
        if (x < 0) { std::cout << "Подстрока " << substring << " не найдена" << std::endl; }
        else { std::cout << "Подстрока " << substring << " найдена по индексу " << x << std::endl; }
    }   while (substring != "exit");

    system("Pause");
}