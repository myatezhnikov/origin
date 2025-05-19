#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

vector<double> intialize(vector<double>& vec, size_t& size)	//Инициализация векторов целыми числами, последовательно
{
	for (size_t i = vec.size(); i < size; i++)
	{
		vec.push_back(i);
	}
	cout << vec.size() << "\t";
	return vec;
}


vector<double> sumVector(vector<double>& vec)		//сумма двух одинаковых векторов
{
	vector<double> sum;
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum.push_back(vec[i]+vec[i]);		
	}
	return sum;
}
void timeLaps(vector<double>& vec)					//подсчет времени выполнения суммирования
{
	auto start = chrono::steady_clock::now();
	sumVector(vec);
	auto end = chrono::steady_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " мс"<< "\t";	//выводим значения в миллисекундах
} 
void print_head(vector<double>& vec)			//однократное выполнение и вывод подсчета времени потоков
{	
	//cout << "\t" << vec.size();
	timeLaps(vec);

}
void print(vector<double>& vec, once_flag& o_flag)		//вывод на экран всех подсчетов
{
	call_once(o_flag, [&vec]() { print_head(vec); });	
	//timeLaps(vec);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int num_Vectors = 4;								//кол-во векторов
	cout << "Количество аппаратных ядер - " << thread::hardware_concurrency() << "\n" << "\n\t\t";	//кол-во ядер

	vector<vector<double>> vectors(num_Vectors);		//создаем вектор векторов (4 вектора с увеличивающимся кол-вом элементов
	size_t num = 1000;									//начальная величина массива элементов для первого вектора
	for (size_t x = 0; x < vectors.size(); x++)
	{
		vectors[x] = intialize(vectors[x], num);		//инициализируем все элементы векторов числами
		num *= 10;
	}
	cout << endl;		
		
	//Начинаем циклы подсчетов и выподим в виде таблицы

		for (int num_threads = 1; num_threads <= 16; num_threads *= 2)	// кол-во потоков двукратно увеличиваем каждый раз
		{		
			cout << num_threads << " потоков\t";			// выводим на экран текущее кол-во потоков
			vector<once_flag> o_flags(vectors.size());		// для каждого вектора свой флаг
			vector<thread> vt;								//вектор потоков
			for (size_t i = 0; i < num_threads; i++)		// для каждого потока
			{				
				for (size_t x = 0; x < vectors.size(); x++)	//считаем сумму каждого вектора и применяем флаг 
				{
					vt.emplace_back(thread(print, ref(vectors[x]), ref(o_flags[x])));
				}		
			}
			for (auto& t : vt)				//ждем выполнения всех потоков
			{
				t.join();
			}			
			vt.clear();				//очищаем потоки
			cout << endl;
		}	
}

