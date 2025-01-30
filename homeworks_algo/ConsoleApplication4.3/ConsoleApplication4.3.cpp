#include <iostream>
#include <Windows.h>
void print_dynamic_array(int* arr, int& logical_size, int& actual_size)
{
    std::cout << "Динамический массив: "; 
    for (int i = 0; i < actual_size; i++)    // Выводим на экран массив
    {      
        if ((logical_size <= i) && (i < actual_size)) { std::cout << "_ "; }
        else { std::cout << arr[i] << " "; }
    }
}

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size)
{
    if ((logical_size - 1) > (actual_size / 3)) // если логический строго более 1/3 фактического
    {
        for (int i = 1; i < logical_size; i++)
        {
            arr[i - 1] = arr[i];            //сдвигаем массив влево
        }
        logical_size -= 1;
    }
    else
    {
        actual_size /= 3;
        int* arr1 = new int[actual_size]; // Иначе создаем новый массив втрое меньше
        logical_size -= 1; // уменьшаем логический размер
        for (int i = 0; i < logical_size; i++)
        {
            arr1[i] = arr[i+1];                   //Копируем в него старый со сдвигом влево
        }

        delete[] arr;
        arr = arr1; // Указатель на новый массив       
       

    }
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int actual_size, logical_size, x = 0;
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
      
    std::string s;
   
    do
    {   
       
        std::cout << std::endl << "Удалить первый элемент ? ";
        std::cin >> s;
        if (s == "нет") { break; }
        if ((logical_size) == 0)
        {
            std::cout << std::endl << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
            return 0;
        }
        remove_dynamic_array_head(arr, logical_size, actual_size);
        print_dynamic_array(arr, logical_size, actual_size);
    } while (s != "нет");
    

    std::cout << std::endl << "Спасибо! ";
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
}