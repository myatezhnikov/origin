#include <iostream>
#include<fstream>

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
void dfs(bool** graf, int V, bool* visited, int& N)  // основная функция поиска вершин
{   
    visited[V] = true;                               // указываем вершину V посещённой
    std::cout << V + 1 << " ";                       // выводим её на экран
    for (int i = 0; i < N; i++)                      //проходим циклом по всем возможным смежным верщинам
    {       
        if (graf[V][i])                              // еслин находим смежную вершину, то проверяем её на посещение
        {
            if (!visited[i]) dfs(graf, i, visited, N); // если это новая, то запускаем рекурсивно с этой новой вершины         
        }
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
        bool* visited = new bool[N] {};             // массив посещенных вершин графа boolean      
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

        dfs(graf, 0, visited,N);                    // запускаем обход

        for (int i = 0; i < N; i++) { delete[] graf[i]; }      //Очистка памяти динамических массивов
        delete[] graf, visited;
    }
    else std::cout << "Не получилось открыть файл!" << std::endl;
    std::cout << std::endl;
    system("Pause");
}