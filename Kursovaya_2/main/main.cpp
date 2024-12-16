#include <iostream>
#include <cmath>
#include <cstdlib>
#include"Transport.h"
#include"Ground.h"
#include"Camel.h"
#include"Speedy_Camel.h"
#include"Centaur.h"
#include "All_terrain_boots.h"
#include"Magic_Carpet.h"
#include"Eagle.h"
#include"Broom.h"

using namespace std;

enum class Transports 
{ All_terrain_boots=1, Broom, Camel, Centaur, Eagle, Speedy_Camel, Magic_Carpet, End }; // Последнее значение это кол-во членов в enum
const int get_size_enum_Transport() { return static_cast<int>(Transports::End); } //Кол-во членов enum

enum class Races
{ Ground=1, Air, Ground_Air, End }; // Типы гонок, последний член для вычисления длины enum
const int get_size_enum_Races() { return static_cast<int>(Races::End); } //Кол-во членов enum


string print_transport(int* i) // Вывод на экран виды транспорта enum
{
	switch (*i)
	{
	case 0: return "Закончить регистрацию";
	case static_cast<int>(Transports::All_terrain_boots): { All_terrain_boots a; return (a.get_Name()); }
	case static_cast<int>(Transports::Broom): { Broom a; return a.get_Name(); }
	case static_cast<int>(Transports::Camel): { Camel a; return a.get_Name();}
	case static_cast<int>(Transports::Centaur): { Centaur a; return a.get_Name(); }
	case static_cast<int>(Transports::Eagle): { Eagle a; return a.get_Name(); }
	case static_cast<int>(Transports::Speedy_Camel): { Speedy_Camel a; return a.get_Name(); }
	case static_cast<int>(Transports::Magic_Carpet): { Magic_Carpet a; return a.get_Name(); }
	default: return "";
	}
};
static string print_type_of_race(int *i) // Вывод на экран одной конкретной гонки
{
	switch (*i)
	{
	case static_cast<int>(Races::Ground): return "Гонка для наземного транспорта"; break;
	case static_cast<int>(Races::Air): return "Гонка для воздушного транспорта"; break;
	case static_cast<int>(Races::Ground_Air): return "Гонка для наземного и воздушного транспорта"; break;
	default: return "";
	}
};

class Racers // Вспомогательный класс участников гонки
{
public:
	Racers(string s_name, double s_travel_time) 
	{	
		name = s_name; travel_time = s_travel_time;
	}
	Racers() { name = ""; travel_time = 0; }
	double get_Time() { return travel_time; }	
	string get_Name() { return name; }
	void set_racer(string s_name, double s_travel_time) 
	{
		name = s_name; travel_time = s_travel_time;
		//travel_time = round(s_travel_time * 10 / 10); // округляем
		//travel_time = (int)(s_travel_time * 100 + 0.5) / 100.;
	}
protected:
	string name{ "" }; double travel_time = 0;  // поля имя и время в пути гонщика
	
};
bool chek_race_transport(Transport t, int type_of_race)
{
	//cout << type_of_race << endl; system("Pause");
	switch (type_of_race)
	{
	case static_cast<int>(Races::Ground): 
	{
		Ground a;
		if (t.get_Type_Transport() == a.get_Type_Transport()) { return true; }
		break;
	}
	case static_cast<int>(Races::Air):
	{
		Air a;
		if (t.get_Type_Transport() == a.get_Type_Transport()) { return true; }
		break;
	}
	case static_cast<int>(Races::Ground_Air): { return true; break; }
	}	
	return false;
}

bool registration(Racers* r, int* choice, int* distance, int type_of_race) // Регистрация транспорта на гонку
{	
	switch (*choice)
	{
	//case 0: return 0;
	case static_cast<int>(Transports::All_terrain_boots): { All_terrain_boots a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Broom): { Broom a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Camel): { Camel a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Centaur): { Centaur a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Eagle): { Eagle a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; }break; }
	case static_cast<int>(Transports::Speedy_Camel): { Speedy_Camel a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	case static_cast<int>(Transports::Magic_Carpet): { Magic_Carpet a; if (chek_race_transport(a, type_of_race)) { r->set_racer(a.get_Name(), a.travel_time(*distance)); return 1; } break; }
	default: return 0;
	}
	return 0;	
};

bool chek_registration(Racers* r, int size, int choice) //Функция проверки уже зарегистрированных ТС
{ 
	for (int i=1; i<=size; i++)
	{
		if (r[i].get_Name() == print_transport(&choice)) { return false; }
	}
	return true; 
}


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
		else if ((choice != 0) && (number_transport < (size-1))) // Если выбор не 0 и кол-во ТС меньше максимального кол-во ТС
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
			} else { system("cls"); cout << print_transport(&choice) << " уже зарегистрирован!" << endl;
			}
		} 
		else if (number_transport == (size - 1)) //Если все ТС зарегистрированы
			{ 
				cout << "Все транспортные средства зарегистрированы" << endl << "Нажмите любую клавишу: ";
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
	for (int i = 1; i < size; i++)	{ cout << i << ". " << print_type_of_race(&i) << endl; }
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

		//if ((choice !=1) || (choice !=1)) { cout << "Неправильно введены данные" << endl;
		//if (choice == 1) { continue; }
	} while (choice != 2);
}