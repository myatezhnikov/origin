#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>  //шаблонная функция
T square(T &x)
{
    return x * x;
}
template<>                //специализация шаблона для вектора
std::vector<int> square(std::vector<int> &array)
{
    std::vector<int> temp_array; //временный вектор
    for (auto var : array)
    {
        temp_array.push_back(var * var); //записываем новое значение
    }
    return temp_array; //возвращаем новый вектор
}

int main()
{
    int x = 4;
    std::cout << "[IN]: " << x << std::endl;
    std::cout << "[OUT]: " << square(x) << std::endl;   // возведение в квадрат числа int

    std::vector<int> data {-1, 4, 8};                   //вектор
    std::cout << "[IN]: ";  
    for (auto var : data)                               //выводим на экран
    {
        std::cout << var << ", ";
    } 
    std::cout << std::endl;
    data = square(data);                                //новый вектор в квадрате   
    std::cout << "[OUT]: "; 
    for (auto var : data)                               //выводим на экран
    {
        std::cout << var << ", ";
    }
}