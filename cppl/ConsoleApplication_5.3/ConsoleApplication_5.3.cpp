#include <iostream>
#include <vector>
#include <algorithm>

class Counter {          
public:
    Counter() : sum(0), count(0) {} //конструктор
    void operator() (int i) 
    { 
        std::cout << i << " "; // выводим на экран все числа вектора последовательно
        if (i % 3 == 0)         // проверяем деление на 3 без остатка
        {
           this->sum += i;      //суммируем
           this->count++;       //считаем кол-во чисел делящихся на 3
        }
    }
int get_sum()
{
    return sum;
}
int get_count()
{
    return count;
}
private:
    int sum;    //переменная сумма
    int count;  //переменная счетчик
};

int main()
{
     Counter new_counter;   
    
    std::vector<int> data{ 4, 1, 3, 6, 25, 54 };    //создадим вектор чисел
    std::cout << "[IN]: ";

    for (int number : data) 
    {
        new_counter(number);                        //выводим на экран и одновременно считаем сумму и количество, operator()
    }  
   std::cout << std::endl << "[OUT]: get_sum() = " << new_counter.get_sum();    // выводим на экран сумму
   std::cout << std::endl << "[OUT]: get_count() = " << new_counter.get_count();    //выводим на экран кол-во чисел
}