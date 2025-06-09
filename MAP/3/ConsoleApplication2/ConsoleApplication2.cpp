#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <iterator> 
using  namespace std;

const size_t threshold = 1000;                  // Пороговое значение для разделения
template<typename Iterator, typename Func>

void parallel_for_each(Iterator begin, Iterator end, Func func)     // функция параллельного for_each
{
    size_t distance = std::distance(begin, end);
    if (distance <= threshold)                            // Если диапазон меньше порога (1000) то, обрабатываем обычно
    {       
        for_each(begin, end, func);  
    }
    else 
    {       
        Iterator mid = begin;                // иначе делим диапазон пополам
        advance(mid, distance / 2);
       
        auto handle1 = std::async(std::launch::async, parallel_for_each<Iterator, Func>, begin, mid, func);  // две асинхронные задачи для обеих половин
        auto handle2 = std::async(std::launch::async, parallel_for_each<Iterator, Func>, mid, end, func);   // для обеих половин
              
        handle1.get();
        handle2.get();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
   
    std::vector<int> data(15);   
    cout << "Исходные элементы: "; 
    for (int i = 0; i < data.size(); ++i)                    // Создаем вектор элементов
    {
        data[i] = i;  
        cout << data[i] << " ";
    }
    cout << endl;

    auto print_element = [](int& x) { x *= 2;  };                // выводим каждый элемент и умножаем на 2             
       
    parallel_for_each(data.begin(), data.end(), print_element);      // параллельный for_each
       
    cout << "Элементы после умножения: ";             // Проверяем первые 25 элементов
    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}