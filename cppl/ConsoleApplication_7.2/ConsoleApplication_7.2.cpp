#include <iostream>
#include <string>
#include <algorithm>
#include <list>

int main()
{
    int x;
    std::list<int> numbers;
    std::cout << "[IN]:" << std::endl;
    std::cin >> x;
    for (int i = 0; i < x; i++)            
    {
        int y;
        std::cin >> y;
        numbers.push_back(y);              //Заносим числа в список
    }
    std::cout << "[OUT]:" << std::endl;

    numbers.sort();     //делаем сначала сортировку, чтобы было проще удалять одинковые числа
    numbers.unique();   //удаляем одинаковые числа

    for (auto it = numbers.rbegin(); it != numbers.rend(); it++)    //выводим в обратном порядке на экран
    {
        std::cout << *it << std::endl;
    }
    system("Pause");
}