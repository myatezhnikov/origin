#include <iostream>
void print_dynamic_array(int* arr, int& logical_size, int& actual_size)
{
    std::cout << "Динамический массив: ";   
    for (int i = 0; i < actual_size; i++)    // Выводим на экран массив
    {
        if ((logical_size <= i) && (i < actual_size)) { std::cout << "_ "; }
        else { std::cout << arr[i] << " "; }
    }
}
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int& x)
{
    if (logical_size < actual_size)   //Если еще есть место в массиве, то просто добавляем элемент
    {
        arr[logical_size] = x;
        logical_size += 1;       
    }
    else                                  
    {
        actual_size *= 2;
        int* arr1 = new int[actual_size]; // Иначе создаем новый массив вдвое больше
        for (int i = 0; i < logical_size; i++) 
        {
            arr1[i] = arr[i];                   //Копируем в него старый
        }
                            
        delete[] arr; 
        arr = arr1; // Указатель на новый массив
        arr[logical_size] = x; // Добавляем новый элемент
        logical_size += 1; // Увеличиваем логический размер
      
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int  actual_size, logical_size, x=0;
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    do
    {
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
        if (logical_size > actual_size) { std::cout << "Логический размер массива не может превышать его фактический размер" << std::endl; }
    } while (logical_size > actual_size);

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }
 
    print_dynamic_array(arr, logical_size, actual_size);
        
    do 
    {
        std::cout << std::endl << "Введите элемент для добавления: ";
        std::cin >> x;
        if (x == 0) { break; }
        append_to_dynamic_array(arr, logical_size, actual_size, x);      
        print_dynamic_array(arr, logical_size, actual_size);
    } while (x != 0);

    std::cout << std::endl << "Спасибо! ";
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
}