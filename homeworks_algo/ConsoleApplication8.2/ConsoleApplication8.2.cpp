#include <iostream>
#include<fstream>
#include <list>

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
void dfs(bool** graf, int V, bool* visited, int& N, std::list<int> &order)  // основная функция поиска вершин
{
    visited[V] = true;                               // указываем вершину V посещённой
   
    for (int i = 0; i < N; i++)                      //проходим циклом по всем возможным смежным верщинам
    {
        if (graf[V][i])                              // еслин находим смежную вершину, то проверяем её на посещение
        {
            if (!visited[i]) dfs(graf, i, visited, N, order); // если это новая, то запускаем рекурсивно с этой новой вершины         
        }
    } order.push_front(V);                          // после прохождения смежных вершин вставляем вершину в начало списка order
}
void top_sort(bool** graf, int &N)
{
    std::list<int> order {};                    // создаем список вершин
    bool* visited = new bool[N] {};             // массив посещенных вершин графа boolean=false   
    for (int i = 0; i < N; i++)
    {
        if (!visited[i]) dfs(graf, i, visited, N, order); // Если еще не посещали, то запускаем рекурсивно dfs
    }
    delete[] visited;                            //Очистка памяти динамического массива
    std::cout << std::endl << "Топологический порядок вершин: ";
    for (int i : order) std::cout << i+1 << " ";  // Перебор отсортированных элементов списка
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
       
       // bool* order = new bool[N] {};
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
       
        top_sort(graf, N);                          // запуск сортировки
       
        for (int i = 0; i < N; i++) { delete[] graf[i]; }      //Очистка памяти динамических массивов
        delete[] graf;
    }
    else std::cout << "Не получилось открыть файл!" << std::endl;
    std::cout << std::endl;
    system("Pause");
}