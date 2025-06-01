#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>
#include <mutex>
using namespace std;

class Data {
public:
    int x;
    double y;
    mutable mutex mutex1;

    Data(int a = 0, double b = 0.0) : x(a), y(b) {} //инициализируем начальными значениями

    void print_out()                                //вывод на экран 
    {
        lock_guard<mutex> lock(mutex1);             //блокируем
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

void swap_lock(Data& a, Data& b) 
{   
    lock(a.mutex1, b.mutex1);
    lock_guard<mutex> lock_a(a.mutex1, adopt_lock);
    lock_guard<mutex> lock_b(b.mutex1, adopt_lock);
    
    swap(a.x, b.x); // меняем местами х и у используя функцию swap
    swap(a.y, b.y);
}

void swap_scoped_lock(Data& a, Data& b) 
{   
    scoped_lock lock(a.mutex1, b.mutex1);
    swap(a.x, b.x);
    swap(a.y, b.y);
}

void swap_unique_lock(Data& a, Data& b) {
    unique_lock<mutex> lock_a(a.mutex1, defer_lock);
    unique_lock<mutex> lock_b(b.mutex1, defer_lock);
 
    lock(lock_a, lock_b); 
    swap(a.x, b.x);
    swap(a.y, b.y);
}

int main() 
{   
    setlocale(LC_ALL, "Russian");
    Data data1(1, 1.5);     //создаем скалярные данные
    Data data2(2, 2.5);
   
    cout << "Начальное значение: " << endl;    
    data1.print_out();
    data2.print_out();   

  
    auto thread1 = thread(swap_scoped_lock, ref(data1), ref(data2));   
   
    thread1.join();  
       
    cout << "После обмена scoped_lock: " << endl;
    data1.print_out();
    data2.print_out();

    auto thread2 = thread(swap_lock, ref(data1), ref(data2));
    thread2.join();
    cout << "После обмена lock: " << endl;

    data1.print_out();
    data2.print_out();

    auto thread3 = thread(swap_unique_lock, ref(data1), ref(data2));
    thread3.join();
    cout << "После обмена unique_lock: " << endl;
    data1.print_out();
    data2.print_out();

    return 0;
}