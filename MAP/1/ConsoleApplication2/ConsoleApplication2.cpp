#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

vector<double> intialize(vector<double>& vec, size_t& size)	//Инициализация векторов целыми числами, последовательно
{
	for (size_t i = vec.size(); i < size; i++)
	{
		vec.push_back(i);
	}
	cout << vec.size() << "\t\t";
	return vec;
}


void sumVector(const vector<double>& vec1, const vector<double>& vec2, vector<double>& vec3, size_t start, size_t end)		//сумма двух одинаковых векторов
{
	for (size_t i = start; i < end; i++)
	{
		vec3[i] = vec1[i] + vec2[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int num_Vectors = 4;								//кол-во векторов
	cout << "Количество аппаратных ядер - " << thread::hardware_concurrency() << "\n" << "\n\t\t";	//кол-во ядер

	//создаем вектор векторов (4 вектора с увеличивающимся кол-вом элементов и результирующий
	vector<vector<double>> vectors(num_Vectors);
	vector<vector<double>> result(num_Vectors);

	size_t num = 1000;									//начальная величина массива элементов для первого вектора
	for (size_t x = 0; x < vectors.size(); x++)
	{
		vectors[x] = intialize(vectors[x], num);		//инициализируем все элементы векторов числами
		result[x].resize(vectors[x].size());			//определяем сразу размер суммарного вектора
		num *= 10;
	}
	cout << endl;		
		
	//Начинаем циклы подсчетов и выводим в виде таблицы

	for (int num_threads = 1; num_threads <= 16; num_threads *= 2)	// кол-во потоков двукратно увеличиваем каждый раз
	{
		cout << num_threads << " потоков\t";			// выводим на экран текущее кол-во потоков
		vector<thread> vt;								//вектор потоков
		for (size_t x = 0; x < vectors.size(); x++)		//проходим для каждого вектора		
		{	
			auto start_time = chrono::steady_clock::now();	//начало отсчета времени на суммирование векторов

			size_t part_of_vector = vectors[x].size() / num_threads;	//разбиваем каждый вектор на кол-во частей (диапазонов) равное кол-ву потоков
			for (size_t i = 0; i < num_threads; i++)				//для каждого поотока свой диапазон одного вектора
			{
				size_t start, end;
				start = i * part_of_vector;			//указываем начало диапазона для потока
				if (i == (num_threads - 1))	
					end = vectors[x].size();		//конец диапазона если это последний поток
				else 
					end = start + part_of_vector;	//конец диапазона если поток не последний
				
				vt.emplace_back(thread(sumVector, cref(vectors[x]), cref(vectors[x]), ref(result[x]), start, end));
			}
			auto end_time = chrono::steady_clock::now();	//окончание отсчета времени для суммирования векторов
			cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " мкс" << "\t\t";	//выводим значения в микросекундах
		}
		for (auto& t : vt)				//ждем выполнения всех потоков
		{
			t.join();
		}
		vt.clear();				//очищаем потоки
		cout << endl;
	}			
}	