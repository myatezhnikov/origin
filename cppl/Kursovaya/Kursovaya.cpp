#include <iostream>
#include <fstream>
#include <string> 
#include <map>

class Exceptions
{
public:
    Exceptions(std::string message) : message{ message } {}
    std::string getMessage() const { return message; }
private:
    std::string message;
};

class ini_parser
{
public:
    ini_parser(const std::string& string) : file(string)	// Конcтруктор    
    {              
            if (!file.is_open())
            {
                throw Exceptions{ "Не получилось открыть файл!" };
            }        
    }     
    template<typename T>
    T get_value(const std::string& str)  
    {     
        std::string section, name_var;              //переменные секция и variable
        std::size_t separator = str.find(".");      //разделитель названия строки на секцию и переменную
        
        if (separator == std::string::npos)
        {
            throw Exceptions{ "Нет разделителя '.' секции и переменной" }; //если некорректно заданы названия
        }
        else
        {
            section = str.substr(0, separator); // Название секции от начала строки до separator
            name_var = str.substr(separator + 1);    // Название переменной от separator до конца строки
            std::cout << section << " " << name_var << " ";
        }

        try
        {
            std::string variable = find_section(section, name_var); //вызываем функцию поиска секций

            if constexpr (std::is_same_v<T, int>)   //в C++17        
            {
                return std::stoi(variable); //если переменная типа int то конвертируем из строки в int            
            } 
            else return variable; // если переменная строка, то оставляем как есть        
        }        
        catch (const std::exception& err)
        {
            std::string msg = "Ошибка типа переменной ";
            msg.append(typeid(T).name());
            msg.append(", тип получаемой переменной должен быть string");
            throw Exceptions{ msg };
        }
    }
    ~ini_parser() { file.close(); } //в деструкторе закрываем файл
    
private: 
    std::ifstream file; //переменная файл   

   void find_variables(std::map<std::string, std::string>& map, std::string& line)
    {      //функция поиска переменных в секции
        do 
        {           
            std::getline(file, line);           //берем следующюую строку   
            // если пустая строка или комментарии, продолжаем цикл дальше на следующую строку
            if (line.empty() || line[0] == ';') continue;
            else              
            {
                if ((line[0] == '[')) {break;}  //если началась новая секция, то выходим из цикла

                std::size_t it = line.find("="); // ищем позицию в строке, где =
                if (it != std::string::npos)
                {
                    std::string value1 = line.substr(0, it); // имя переменной
                    std::string value2 = line.substr(it + 1); // значение переменной                   
                    it = value2.find(";");   // Проверяем, есть ли комментарий
                    if (it != std::string::npos)
                    {
                       value2.erase(it); //если есть удаляем комментарий
                    }
                    map[value1] = value2;   //заносим переменные=значения в map
                }
            }   
        } while (!file.eof()); //цикл до конца файла, если секция последняя
    }
   
    std::string find_section(std::string& section, std::string& name_var)  //функция нахождения секции и переменной
    {
       
        std::string line;   //считываемая строка из файла
        std::string value="";   //значение переменной, которую ищем
        std::map<std::string, std::string> map; //контейнер уникальная переменная и значение
        bool is_section=0;  //переменная: falsе секция не найдена, true найдена секция

        while (std::getline(file, line))// || (!file.eof()))    //запускаем цикл построчного прохода файла
        {
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());    //удаляем все пробелы из строки
           
            if (line.find("[" + section + "]") == std::string::npos) 
            { 
                continue;    //если не нашли на этой строке, то переходим на следующую
            }  
            else
            {             
               //std::cout << "Найдена секция " << section << std::endl;
                is_section = true;  //если нашли секцию
               find_variables(map,line); //запускаем поиск переменных               
            }
        } 
        if ((file.eof()) && !is_section) { throw Exceptions{"Нет такой секции"}; } //если не нашли секцию до конца файла

        for (const auto& elem : map)    //перебираем найденные переменные и ищем требуемую
        {
            if (elem.first == name_var)
            {
                value = elem.second;
                return value;   //если нашли, то выходим
            }
        }

        if (value.empty() && map.size())    //если нет этой переменной, но есть другие в этой секции
        {
            std::cout << std::endl << "Нет такой переменной в этой секции, есть другие " << std::endl;
            for (const auto& elem : map)
            {
                std::cout << elem.first << std::endl;   //выводим существующие переменные в этой секции
            }
            throw Exceptions{ "Выберите другую перменную" };
        }
        else throw Exceptions{ "Нет переменных в этой секции" };    //если нет ни одной переменной в этой секции
        return value;
    }      
};

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        ini_parser parser("test.ini");
        auto value = parser.get_value<int>("Section1.var");
        std::cout << "= " << (value) << std::endl;    //выводим искомую перменную
    }
    catch (const Exceptions& ex)
    {
        std::cout << ex.getMessage() << std::endl;  //выводим сообщения о исключениях
    }
    system("Pause");
}