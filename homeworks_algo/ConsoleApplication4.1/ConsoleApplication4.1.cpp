#include <iostream>
void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++)  //Выводим на экран массив
    {
        if ((logical_size <= i) && (i < actual_size)) { std::cout << "_ "; }
        else { std::cout << arr[i] << " "; }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int  actual_size, logical_size;
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    do
    {
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
        if (logical_size > actual_size) { std::cout << "Логический размер массива не может превышать его фактический размер" << std::endl; }
    } while (logical_size > actual_size);

    int* arr = new int[logical_size];
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
     
}