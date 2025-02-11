#include <iostream>
#include<fstream>
#include <Windows.h>

bool** create_two_dim_array(int& rows, int& columns) {     // функция создания двумерного массива
    bool** arr = new bool* [rows];
    for (int i = 0; i < rows; i++) { arr[i] = new bool[columns]; }
    return arr;
}
void print_on_screen(bool**& array, int& rows, int& columns) // функция вывода на экран
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j]) std::cout << '1' << " ";
            else std::cout << '0' << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void dfs(bool** graf, int& N)  
{ 
    std::cout << "Текстовый вид орграфа: " << std::endl;
    for (int i = 0; i < N; i++)  // цикл прохода по строкам
    {
        bool find = false;           // переменная проверки возможности попасть отсюда куда-нибудь 
        std::cout << i + 1 << ": ";
        for (int j = 0; j < N; j++)  // цикл прохода по столбцам
        {
            if (graf[i][j])         // если нашлось куда отправиться из этой вершины
            {
                std::cout << j+1 << " "; find = true;
            }
        } if (!find) std::cout << "нет"; // если нет направления
        std::cout << std::endl;
    }   
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    std::ifstream file("input.txt");                 // Открытие файла
    if (file.is_open())
    {
        file >> N;                                  // считывание чисел вершин (размер массива)
        bool** graf = create_two_dim_array(N, N);   // массив графа boolean       
        while (!(file.eof()))
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    file >> graf[i][j];              // считывание чисел из файла в массив
                }
            }
        }
        file.close();

        print_on_screen(graf, N, N);                // Выводим для наглядности матрицу

        dfs(graf, N);                    // запускаем обход

        for (int i = 0; i < N; i++) { delete[] graf[i]; }      //Очистка памяти динамических массивов
        delete[] graf;
    }
    else std::cout << "Не получилось открыть файл!" << std::endl;
    std::cout << std::endl;
    system("Pause");
}