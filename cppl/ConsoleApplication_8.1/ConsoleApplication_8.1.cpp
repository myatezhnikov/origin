#include <iostream>
#include <algorithm>
#include <vector>
template <typename T>
void print(std::vector<T> vec)      //функция вывода вектора на экран
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
}

int main()
{
    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";   
    print(vec);                                             //выводим на экран
    std::sort(vec.begin(), vec.end());                      //сортируем
    auto it = std::unique(vec.begin(), vec.end());          //отбираем уникальные
    vec.erase(it, vec.end());                               //удаляем лишние
    std::cout << std::endl << "[OUT]: ";
    print(vec);                                             //выводим на экран
    std::cout << std::endl;
    system("Pause");
    return 0;
}
