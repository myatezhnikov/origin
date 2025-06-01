#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
#include <atomic>
using namespace std;

class Variable              //создаем класс для общей перменной подсчета
{
public:
    atomic_int count{ 0 };
};

void client(shared_ptr<Variable> counter)       //увеличение клиентов
{
    while (true)
    {
        int current = counter->count.load(memory_order_acquire);
        if (current >= 10)
        {
            break; // выход
        }
        int new_value = counter->count.fetch_add(1, memory_order_release) + 1;
        cout << "Клиент " << new_value << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
void operationist(shared_ptr<Variable> counter)     //уменьшение очереди клиентов
{
    while (true)
    {
        int current = counter->count.load(memory_order_acquire);
        if (current <= 0) {
            break; // очередь закончилась
        }
        int new_value = counter->count.fetch_sub(1, memory_order_release) - 1;
        cout << "Операционист " << new_value + 1 << endl;
        this_thread::sleep_for(chrono::seconds(2));
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
