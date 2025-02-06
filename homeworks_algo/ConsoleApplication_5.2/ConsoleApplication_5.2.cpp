#include <iostream>
void print_array(int* arr, int x) // функция вывода массива на экран
{
    for (int i = 0; i < x; i++) { std::cout << arr[i] << " "; }
}
// вспомогательные функции из презентации
int from_index(int* arr, int index) { return arr[index]; }
int left_index(int* arr, int index) { return 2 * index + 1; }
int right_index(int* arr, int index) { return 2 * index + 2; }
int parent_index(int* arr, int index) { return (index - 1) / 2; }

void print_pyramid(int* arr, int size, int index, int level)
{
    if (level == 0) { std::cout << "0 root " << from_index(arr, 0) << std::endl; } // нулевой уровень выводим сразу
    else
        for (int j = 1; j <= (2 * level); j++)  // выводим все значения на текущем уровне
        {
            index += 1;  if (index >= size) { return; }  // повышаем индекс и если выходим за пределы маасива, то завершаем процедуру

            if ((index % 2) != 0)  // если нечетное, то левый потомок
            {
                std::cout << level << " left(" << from_index(arr, parent_index(arr, index)) << ") " << from_index(arr, index) << std::endl;
            }
            else if ((index % 2) == 0) // если четное, то правый потомок
            {
                std::cout << level << " right(" << from_index(arr, parent_index(arr, index)) << ") " << from_index(arr, index) << std::endl;
            }
        }
    print_pyramid(arr, size, index, level + 1); // запускаем реурсивно вывод значений
}
void where_i_am(int* arr, int size, int index, int level)
{ 
    std::string str = "";
do
 { begin:
   if (level == 0) { std::cout << "Вы находитесь здесь : 0 root " << from_index(arr, 0) << std::endl; } // нулевой уровень выводим сразу
   else if (level < 0) { std::cout << "Ошибка! Отсутствует родитель" << std::endl; level += 1; goto begin; }
      else
        {
          if ((index % 2) != 0)  // если нечетное, то левый потомок
            {
              if (index >= size) { std::cout << "Ошибка! Отсутствует левый потомок" << std::endl; level -= 1; index = parent_index(arr, index);  goto begin; }
              else std::cout << "Вы находитесь здесь: " << level << " left(" << from_index(arr, parent_index(arr, index)) << ") " << from_index(arr, index) << std::endl;
            }
            else if ((index % 2) == 0) // если четное, то правый потомок
            {
              if (index >= size) { std::cout << "Ошибка! Отсутствует правый потомок" << std::endl; level -= 1; index = parent_index(arr, index);  goto begin; }
              else std::cout << "Вы находитесь здесь: " << level << " right(" << from_index(arr, parent_index(arr, index)) << ") " << from_index(arr, index) << std::endl;
            }
        }  
       std::cout << "Введите команду: ";
       std::cin >> str; //проверяем что было нажато
       if (str == "right") { level += 1; index = right_index(arr, index); }
       if (str == "left") { level += 1; index = left_index(arr, index); }
       if (str == "up") { level -= 1; index = parent_index(arr, index); }
       if (str == "exit") { return; }
   
   } while (str != "exit");

}

int main()
{
    setlocale(LC_ALL, "Russian");
    int* arr1 = new int[6] {1, 3, 6, 5, 9, 8};
   // int* arr1 = new int[8] {94, 67, 18, 44, 55, 12, 6, 42};
   // int* arr1 = new int[10] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    std::cout << "Исходный массив: "; print_array(arr1, 6); std::cout << std::endl;
    print_pyramid(arr1, 6, 0, 0);
    std::cout << std::endl;
    where_i_am(arr1, 6, 0, 0);
  
    delete[] arr1;
}