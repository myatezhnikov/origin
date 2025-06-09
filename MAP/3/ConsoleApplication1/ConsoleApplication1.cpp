#include <iostream>
#include <vector>
#include <future>
#include <algorithm> 
#include <random>   
using namespace std;

size_t find_minimum_element(const std::vector<int>& arr, size_t start, size_t end) // поиск индекса мин элемента от start до end
{
    size_t min_elem = start;
    for (size_t i = start + 1; i < end; ++i) {
        if (arr[i] < arr[min_elem]) {
            min_elem = i;
        }
    }
    return min_elem;
}

int main() {
    setlocale(LC_ALL, "Russian");
   
    const size_t size = 10;
    std::vector<int> arr(size);

    srand(time(0)); 
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++)              // Инициализация массива случайными числами
    {
        arr[i] = (rand() % 5 + 1) + (rand() % 100 + 10);
        cout << arr[i] << " ";
    }
    cout << std::endl;
  
    for (size_t i = 0; i < arr.size(); ++i) 
    {       
        promise<size_t> prom;                       // promise и future для передачи результата поиска минимума
        future<size_t> fut = prom.get_future();
      
        auto search_task = std::async(std::launch::async, [&arr, i, &prom]()      // асинхронная задача поиска минимума
            {
            size_t min_idx = find_minimum_element(arr, i, arr.size());
            prom.set_value(min_idx);
            });

       
        size_t min_elem = fut.get();      // индекс минимального элемента будущего
       
        if (min_elem != i)               // Меняем местами текущий элемент с минимальным
        {
            std::swap(arr[i], arr[min_elem]);
        }
    }
   
    cout << "Отсортированный массив: ";         // Вывод на экран после соритировки
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}