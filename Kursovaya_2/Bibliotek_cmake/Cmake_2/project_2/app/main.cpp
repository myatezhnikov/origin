#include <iostream>
#include"..\lib_func\Functions.h"
#include"..\lib_racers\Racers.h"
#include"..\lib1\Transport.h"
#include"..\lib1.1\Air.h"
#include"..\lib1.1.1\Broom.h"
#include"..\lib1.1.2\Eagle.h"
#include"..\lib1.1.3\Magic_Carpet.h"
#include"..\lib1.2\Ground.h"
#include"..\lib1.2.1\All_terrain_boots.h"
#include"..\lib1.2.2\Camel.h"
#include"..\lib1.2.3\Centaur.h"
#include"..\lib1.2.4\Speedy_Camel.h"

using namespace std;

int registration_racers(int* type_of_race, int number_transport, int distance, Racers* r, int size)
{
	system("cls"); int choice{ 0 };
	do
	{
		//system("cls");
		cout << print_type_of_race(&*type_of_race) << ". Расстояние: " << distance << endl; //Вывод инф. о гонке
		if (number_transport) // Если уже есть ТС
		{
			cout << "Зарегистрированные транспортные средства: ";
			string s;
			for (int i = 1; i <= number_transport; i++)	// Перечислим все зарегистрированные ТС
			{
				if (i > 1) { s += ", "; } // если уже больше одного ТС, то посавить запятую и пробел			
				s += r[i].get_Name();
			}
			cout << s << endl; // Вывод на экран
		};

		for (int i = 0; i < size; i++) // Цикл вывода на экран
		{
			cout << i << ". " << print_transport(&i) << endl; // Вывод на экран всех ТС
		}
		cout << "Выберите транспорт или 0 для окончания процесса регистрации" << endl;
		std::cin >> choice;

		if (choice > (size - 1)) { cout << "Неправильно введены данные" << endl; system("Pause"); continue; } //Проверка на правильность введенных данных

		if ((choice == 0) && (number_transport < 2)) // Если менее двух транспортных средств
		{
			cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << endl;
			cout << "1. Зарегистрировать транспорт" << endl << "Выберите действие: ";

			std::cin >> choice;
			system("cls");
			choice = 1; // не выходим из цикла
		}
		else if ((choice != 0) && (number_transport < (size - 1))) // Если выбор не 0 и кол-во ТС меньше максимального кол-во ТС
		{
			if (chek_registration(r, number_transport, choice)) // Проверяем на одинковые ТС
			{
				number_transport++; //Прибавляем порядковый номер нового участника
				if (registration(&r[number_transport], &choice, &distance, *type_of_race))  //Регистрируем ТС, т.е инициализируем массив racers
				{
					system("cls");
					cout << r[number_transport].get_Name() << " успешно зарегистрирован!" << endl;
				}
				else { system("cls");  cout << "Попытка зерегистрировать неправльный тип транспортного средства" << endl; number_transport--; } //Возвращаем номер участника т.к. регистрация не прошла
			}
			else {
				system("cls"); cout << print_transport(&choice) << " уже зарегистрирован!" << endl;
			}
		}
		if (number_transport == (size - 1)) //Если все ТС зарегистрированы
		{
			system("cls");
			cout << "Все транспортные средства зарегистрированы" << endl << "1. Закончить регистрацию" << endl;
			std::cin >> choice; choice = 0;
		}
	} while (choice);
	return number_transport; //Фактически присваимваем функции кол-во зарегистрированных участников
}
void sorting(Racers* r, int size) //Функция сортировки в массиве участников, вявление победителей
{
	bool swap;
	do
	{
		swap = false;
		for (int i = 1; i <= size; i++)
		{
			if (r[i - 1].get_Time() > r[i].get_Time())
			{
				Racers temp = r[i - 1];
				r[i - 1] = r[i];
				r[i] = temp;
				swap = true;
			}
		}
	} while (swap);
};
void print_result_race(Racers* r, int x) //Функция вывода на экран резульатов
{
	sorting(r, x);
	for (int i = 1; i <= x; i++)
	{
		cout << i << ". " << r[i].get_Name() << ". Время: " << r[i].get_Time() << endl;
	}
}
void print_races(int size) // Вывод на экран всех гонок
{
	for (int i = 1; i < size; i++) { cout << i << ". " << print_type_of_race(&i) << endl; }
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int type_of_race{ 0 }; // Переменная тип гонки
	int number_transport{ 0 }; //Переменная номер выбранного ТС (транспортного средства)
	int choice{ 0 }; //Переменная выбора пользователя (обычно номер ТС или номер действия)
	int distance{ 0 }; // Переменная расстояния вводимого пользователем
	int x{ 0 }; // Переменная количества уже зарегистрированных ТС
	const int size = get_size_enum_Transport(); // Постоянная - вычисляется длина списка ТС перед началом
	const int num_races = get_size_enum_Races(); // Постоянная - вычисляется длина списка гонок перед началом
	Racers* racers = new Racers[size]{}; // Массив возможных участников	

	cout << "Добро пожаловать в гоночный симулятор!" << endl;
	do
	{
		print_races(num_races);
		cout << "Выберите тип гонки: ";
		std::cin >> type_of_race;
		if ((type_of_race > (num_races - 1)) || (type_of_race < 1)) { cout << "Неправильно введены данные" << endl << endl; system("Pause"); continue; }
		cout << "Укажите длину дистанции (должна быть положительна): ";
		std::cin >> distance;
		cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << endl;
		cout << "1. Зарегистрировать транспорт" << endl << "Выберите действие: ";
		std::cin >> choice;
		x = registration_racers(&type_of_race, 0, distance, racers, size);
		do
			{
				system("cls");	
				cout << "1. Зарегистрировать транспорт" << endl;
				cout << "2. Начать гонку" << endl;
				cout << "Выберите действие: ";
				std::cin >> choice;
				if (choice == 1) { x = registration_racers(&type_of_race, x, distance, racers, size); }	
			} while (choice != 2);

		system("cls");
		cout << "Результаты гонки:" << endl;
		print_result_race(racers, x);
		cout << endl;
		cout << "1. Провести ещё одну гонку" << endl;
		cout << "2. Выйти" << endl;
		cout << "Выберите действие: ";
		std::cin >> choice;
				
	} while (choice != 2);
	delete[] racers;
}