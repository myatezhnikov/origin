#include <iostream>
template <typename T>
struct Vector
{
public:
    Vector() : actual_size(1), logical_size(0)  //инициализация переменных и массива
    {
        arr = new T[actual_size];
    }   
   T at(int index)                          //доступ к элементу контейнера по индексу
   {
       try
       {
           if (index < actual_size) return arr[index];      //проверяем на выход за диапазон
           else throw(index);                              
       }
       catch (int index) {
           std::cout << std::endl << index << " index - out of range" << std::endl; //вышли за диапазон
           return 0;
       }
   };
   void push_back(T value)      //вставка в конец контейнера (массива)
   {
       if (logical_size >= actual_size)   //Если массив уже полный, то создаем вдвое больше
       {           
           actual_size *= 2;
           T* arr1 = new T[actual_size]; //новый временный массив
           for (size_t i = 0; i < logical_size; i++)
           {
               arr1[i] = arr[i];                   //Копируем в него старый
           }
           delete[] arr;
           arr = arr1; // Указатель на новый массив
       }
       arr[logical_size] = value; // Добавляем новый элемент
       logical_size++; // Увеличиваем логический размер
   
   };
   size_t size()                //размер элементов в контейнере равен логическому размеру массива
   {
       return logical_size;
   };
   size_t capacity()             //емкость контейнера равна фактическому размеру массива
   {
       return actual_size;
   };
  
   ~Vector() { delete[] arr; };  //деструктор удаляем динамический массив

private:
    size_t actual_size;  //фактический размер  capacity
    size_t logical_size;   //логический размер
    T* arr; //создаем массив с начальным размером 1
};

int main()
{    
    Vector<int> vec;
    std::cout << "Size first: " << vec.size() << std::endl; //первоначальный размер, кол-во элементов в контейнере
    vec.push_back(5);                                       //заносим элементы в контейнер
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);

    std::cout << "Size after push_back: " << vec.size() << std::endl;   //размер послпе добавления элементов
    std::cout << "Numbers: ";                               
    for (size_t i=0; i<vec.size(); i++)                                    //выводим все добавленные элементы на экран
    {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl << "Capacity: " << vec.capacity() << std::endl;  //емкость контейнера, сколько еще можно добавить
    vec.at(10); //проверяем выход за пределы диапазона контейнера
    system("Pause");
}

