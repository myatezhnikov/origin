#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <stdexcept>

using namespace std;

class IniException
{
public:
	IniException(string message) : message{ message } {}
	string getMessage() const { return message; }
private:
	string message;
};

class IniParser {
public:
	IniParser(const string& fileName) : file(fileName)	// Конcтруктор    
	{
		if (!file.is_open())			//открываем файл
		{
			throw IniException{ "Не получилось открыть файл!" };
		}
		iniData = make_unique<map<string, map<string, string>>>(); //инициализируем уникальный указатель карта карт
		reading_file();	//считываем весь файл в карту карт
		file.close();	//закрываем файл, т.к. он больше не нужен
	}

	//1. Основной шаблон, по которому будет проводиться сопоставление
	template<typename T>
	T get_value(const string& section, const string& var) { //вместо тела, можно поставить ; будет просто ошибка компиляции
		//Тут только одно предупреждение, чтобы сказать, что надо пользоваться уже заданными конвертациями
		static_assert(sizeof(T) == -1, "not implemented type for get_value");
	}

	~IniParser() {}

private:
	ifstream file; //переменная файл   
	//создаем уникальный укзатель (карта карт) для считывания данных из файла
	unique_ptr<map<string, map<string, string>>> iniData;

	string get_value_string(const string& section, const string& var)
	{
		// ищем в iniData секцию и переменную
		auto it_section = iniData->find(section);
		if (it_section != iniData->end())
		{
			auto it_var = it_section->second.find(var);
			if (it_var != it_section->second.end())
			{
				return it_var->second;
			}
			else 
			{	//если нет таких переменных, то выводим список существующих
				if (it_section->second.empty()) throw IniException{ "В этой секции нет переменных" };
				cout << "Переменная " << var << " не найдена, в секции " << section << " есть переменные : ";
				for (const auto& tmp_var : it_section->second)
				{
					cout << tmp_var.first << " ";
				} cout << endl;
			}
		}
		else
		{
			//если нет такой секции, то выводим список существующих
			if (iniData->empty()) throw IniException{ "Нет ни одной секции в этом файле" };
			cout << "Секция " << section << " не найдена, в этом файле есть секции: ";
			for (const auto& tmp_section : *iniData)
			{
				cout << tmp_section.first << " ";
			}	cout << endl;
		}
		//если не нашли бросаем исключение
		throw IniException{ "Введите корректные данные" };
		//return "";
	}

	bool find_section_var(map<string, string>& variables, string& line)  //функция поиска секций и переменных в секции
	{    								
		while (getline(file, line))
		{
			// если пустая строка или комментарии, продолжаем цикл дальше на следующую строку
			if (line.empty() || line[0] == ';') continue;
			else
			{
				if ((line[0] == '[')) { return true; }  //если началась новая секция, то выходим из цикла
				else
				{
					size_t it = line.find("="); // итератор, ищем позицию в строке, где =
					if (it != std::string::npos)
					{
						string var_name = line.substr(0, it); // имя переменной
						string var_value = line.substr(it + 1); // значение переменной                   
						it = var_value.find(";");   // Проверяем, есть ли комментарий
						if (it != std::string::npos)
						{
							var_value.erase(it); //если есть удаляем комментарий
						}
						variables.insert(make_pair(var_name, var_value));	//вставляем в карту переменную и значение
					}
				}
			}
		} return false;
	}
	//void chek_section(map <string, map <string, string>>& iniData, const string& section, map <string, string>& var)
	void chek_section(const string& section, map <string, string>& var)
	{	//проверяем секции на дубликаты
		for (auto& i_section : *iniData)
		{
			if (i_section.first == section)
			{
				for (auto& i_var : i_section.second)
				{	// проверяем существует ли переменная, если да, то заменяем													
					var.insert(make_pair(i_var.first, move(i_var.second)));
				}
			}
		}
	}

	void reading_file()     //Функция считывания файла в карту карт
	{
		string line = "";							//считываемая строка из файла		
		//map <string, map <string, string>> iniData;    //карта уникальных секций, второй элемент 
		//- карта уникальных переменных и их значений		

		while (getline(file, line))    //запускаем цикл построчного прохода файла
		{
			bool out_from_section = false; //если функция find_variables нашла новую секцию то true, выходим из find_section_var
			//чтобы проверить секции на повтор и записать нвые значиня в карты (mар)	
				
			do
			{
				string section = line.substr(1, line.find(']') - 1);
				map<string, string> var;	 //карта уникальных переменных и их значений
				out_from_section = find_section_var(var, line);		//запускаем функцию поиска переменных в секции
				//проверяем на наличие уже существующей секции, если есть то добавляем перменнеые или меняем существующие
				chek_section(section, var);
				//вставляем в карту новые переменные				
				(*iniData)[section] = var;

			} while (out_from_section);
		}	//окончание цикла считываения файла
		
			//Выводим на экран все считанные секции и переменные для проверки
		/*cout << endl << "Считанный файл" << endl;
		for (const auto& i_section : *iniData) {
			cout << i_section.first << endl;
			for (const auto& i_variable : i_section.second) {
				cout << "  " << i_variable.first << " = " << i_variable.second << endl;
			}
		}*/
	}
};

//2. конкретный шаблон для стринга
template<>
string IniParser::get_value(const string& section, const string& var) {
	return get_value_string(section, var);
}
//3. конкретный шаблон для инта
template<>
int IniParser::get_value(const string& section, const string& var) {
	string strval = get_value_string(section, var);
		
	//удаляем все пробелы из строки на всякий случай
	strval.erase(std::remove_if(strval.begin(), strval.end(), ::isspace), strval.end()); 
	try {
		return stoi(strval);
	}	
	catch (const invalid_argument&) {
		throw IniException("Ошибка конвертации в int: ");
	}	
}
template<>
double IniParser::get_value(const string& section, const string& var) {
	string strval = get_value_string(section, var);
	//удаляем все пробелы из строки на всякий случай
	strval.erase(std::remove_if(strval.begin(), strval.end(), ::isspace), strval.end());
	return stod(strval);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		IniParser parser("test.ini");
		cout << parser.get_value<string>("Section1", "var2") << endl;
		cout << parser.get_value<int>("Section2", "var1") << endl;
		//если раскоммнетируем, то увидим ошибку времени компиляции:
		cout<<parser.get_value<double>("Section4","var2")<<endl;
	}
	catch (const IniException& e)	//обработка своих исключений
	{	
		cout << e.getMessage() << endl;
	}
	catch (const std::exception& e)	//обработка стандартных исключений
	{
		cout << "Ошибка: " << e.what() << endl;
	}
}