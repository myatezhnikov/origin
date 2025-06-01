#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <iomanip>
#include <ctime>

using namespace std;

mutex cout_mutex;

void move_cursor_to_line(int line)      // перемещение курсора на нужную строку (относительно текущей позиции)
{
    cout << "\033[" << line << ";0H";
}

void immitation_work(int index, int progress_length, int wait) // иммитация многопоточного расчёта.
{
    auto start_time = chrono::steady_clock::now();
    auto end_time = start_time;
    chrono::duration<double> elapsed;
    thread::id this_id = this_thread::get_id();

    int line_number = index + 2;    // +2 чтобы оставить место для заголовка    
    string progress_bar;            // переменная для хранения состояния   

    for (int i = 0; i <= progress_length; ++i) {
        
        this_thread::sleep_for(chrono::milliseconds(100 + rand() % 200)); // Имитация работы с задержкой
       
        progress_bar.clear();                                        // Обновляем строку прогресс-бар
        for (int j = 0; j < i; ++j) progress_bar += "\033[47m" " " "\033[0m"; // закрашенные символы
        for (int j = i; j < progress_length; ++j) progress_bar += " ";
     
        end_time = chrono::steady_clock::now();
        elapsed = end_time - start_time;
      
        {
            lock_guard<mutex> lock(cout_mutex);
            move_cursor_to_line(line_number);
            // Выводим строку прогресс-бар 
            cout << setw(1) << index + 1 << " "
                << setw(6)
                << this_id << " "                
                << setw(20)
                << progress_bar << " "
                << fixed
                << elapsed.count() << "s";
        }

        // Задержка между символами, чтобы было видно постепенное заполнение
        this_thread::sleep_for(chrono::milliseconds(wait + rand() % 90));
    }       
    
}

int main() {
    setlocale(LC_ALL, "");

    int num_threads = 5;       // Количество потоков
    int progress_length = 20;  // Длина строки прогресс-бара

    vector<thread> threads;
    srand(time(nullptr));  
    cout << "#    id     progress bar       time";       //Заголовок    
   
    for (int i = 0; i < num_threads; ++i)  // Запускаем потоки
    {     
        int wait = 50 + rand() % 90;   //задрежка вывода символов для текущего потока   
        threads.emplace_back(immitation_work, i, progress_length, ref(wait));
        this_thread::sleep_for(chrono::milliseconds(100)); // задержка между запуском потоков
    }

    for (auto& t : threads) t.join();

    return 0;
}