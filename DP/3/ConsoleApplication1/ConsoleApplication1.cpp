#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LogCommand        // Базовый класс
{
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand         // вывод на консоль
{
public:
    void print(const std::string& message) override 
    {
        cout << message << endl;
    }
};

class FileLogCommand : public LogCommand        // вывод в файл 
{
public:
    explicit FileLogCommand(const std::string& file_path) : file_path_(file_path) {}

    void print(const string& message) override 
    {
        ofstream ofs(file_path_, ios_base::app);        //добавление лог в конец файла
        if (ofs.is_open()) 
        {
            ofs << message << endl;
        }
        else 
        {
            cerr << "Failed to open file: " << file_path_ << endl;
        }
    }

private:
    string file_path_;
};

void execute(LogCommand& command, const std::string& message)       // выполнения команды
{
    command.print(message);
}

int main()
{
    ConsoleLogCommand console_command;
    FileLogCommand file_command("log.txt");

    execute(console_command, "log output in console");
    execute(file_command, "Log output in file log.txt");

}