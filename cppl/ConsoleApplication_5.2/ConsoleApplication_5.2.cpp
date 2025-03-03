#include <iostream>
#include <vector>

template <typename T>
class Table
{
public:
    Table(size_t rows, size_t columns) : rows(rows), columns(columns) //конструктор принимающий кол-во строк и столбцов
    {
        data.resize(rows);       //количество строк
        for (int i = 0; i < rows; i++)
        {
            data[i].resize(columns);    //кол-во столбцов
        }
        for (int i = 0; i < rows; i++)  //инициализируем нулями строки
        {
            for (int j = 0; j < columns; j++)   // и столбцы
                data[i][j] = 0;
        }
    };     
std::vector<T>& operator[](size_t i) //неконстантная версия для записи
{
    return data[i];
}
const std::vector<T>& operator[](size_t i) const   //константная для чтения
{
    return data[i];
}
std::pair<size_t, size_t> Size() const //парная переменная константная для чтения размера таблицы
{
    return { rows, columns }; //два значения - строки и столбцы
}
private:
    size_t rows;
    size_t columns;
    std::vector<std::vector<T>> data;
};

int main()
{
    Table<int> test(2, 3);
    test[0][0] = 4;                                               // присваиваем новое значение
    std::cout << test[0][0] << std::endl;                         // выводим значение
    std::cout << test.Size().first << " " << test.Size().second;  // выводим размер таблицы
    
}