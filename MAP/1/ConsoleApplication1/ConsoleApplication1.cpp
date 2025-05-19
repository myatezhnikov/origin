#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
using namespace std;

class Variable              //создаем класс для общей перменной подсчета
{
public:
    int count=0;
};

void client(shared_ptr<Variable> counter)       //увеличение клиентов
{
    while (counter->count < 10)     // не более 10 клиентов
    {       
        counter->count++;       
        cout << " клиент " << counter->count << endl;
        this_thread::sleep_for(chrono::seconds(1)); //задержка 1 секунда
    }
}
void operationist(shared_ptr<Variable> counter)     //уменьшение очереди клиентов
{
    while (counter->count > 0)      //уменьшаем до последнего
    {       
        counter->count--;      
        cout << " операционист " << counter->count << endl;
        this_thread::sleep_for(chrono::seconds(2)); //задержка 2 секунды
    } 
}

int main()
{
    setlocale(LC_ALL, "Russian");
    auto count = make_shared<Variable>();   //создаем переменную для совместного использования
    thread t1(client, ref(count));          //передаем в потоки
    thread t2(operationist, ref(count));
    t1.join();
    t2.join();  
    
}
