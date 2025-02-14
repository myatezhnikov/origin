#include <iostream>

void print_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
}
void count_sort(int* arr, int size)         // сортировка подсчётом
{     
    int counts[15] = {0};                    // весь массив из чисел 10 < x < 24, значит всего 14 разных чисел
    int c = 0;
    for (int i = 0; i < size; i++)         
    {
        if (arr[i] >= 10 && arr[i] <= 24)    // на всякий случай проверяем чтоб было в диапазоне
        {
            counts[arr[i] - 10] += 1;        // считаем сколько раз встретилось число, начинаем с 0-го элемента
        }
    } 
    for (int i = 0; i < 15; i++)
    {
        while (counts[i] > 0)           // пока все числа не выведены на экран
        {                
            arr[c] = i + 10;            // вощвращаем реальное значения числа, прибавляем 10
            c += 1;
            counts[i] -= 1;             // понижаем счетчик уже напечатанного числа
        }
    }  
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    std::cout << "Исходный массив: ";
    print_arr(arr1, 30);
    count_sort(arr1, 30);
    std::cout << std::endl << "Отсортированный массив: ";
    print_arr(arr1,30);
    std::cout << std::endl << std::endl;

    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    std::cout << "Исходный массив: ";
    print_arr(arr2, 40);
    count_sort(arr2, 40);
    std::cout << std::endl << "Отсортированный массив: ";
    print_arr(arr2, 40);
    std::cout << std::endl << std::endl;

    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
    std::cout << "Исходный массив: ";
    print_arr(arr3, 45);
    count_sort(arr3, 45);
    std::cout << std::endl << "Отсортированный массив: ";
    print_arr(arr3, 45);
    std::cout << std::endl << std::endl;

    system("pause");
}
