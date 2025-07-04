#include <string>
#include <stdexcept>
#include <memory>
#include <fstream>
#include <iostream>
using namespace std;

enum class MessageType 
{
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage 
{
public:
    LogMessage(MessageType t, const string& msg) : type_(t), message_(msg) {}
    MessageType type() const { return type_; }
    const string& message() const { return message_; }

private:
    MessageType type_;
    string message_;
};

class LogHandler 
{
public:
    virtual ~LogHandler() = default;

    void setNext(std::shared_ptr<LogHandler> nextHandler) 
    {
        next_ = nextHandler;
    }

    void handle(const LogMessage& msg) 
    {
        if (canHandle(msg.type())) 
        {
            process(msg);
        }
        else if (next_) 
        {
            next_->handle(msg);
        }
        else 
        {           
            throw std::runtime_error("Необработанное сообщение " + msg.message());   // если некому обработать, то исключение
        }
    }

protected:
    virtual bool canHandle(MessageType type) const = 0;
    virtual void process(const LogMessage& msg) = 0;

private:
    shared_ptr<LogHandler> next_;
};

class FatalErrorHandler : public LogHandler 
{
protected:
    bool canHandle(MessageType type) const override 
    {
        return type == MessageType::FatalError;
    }

    void process(const LogMessage& msg) override 
    {
        throw std::runtime_error("Fatal_Error " + msg.message());
    }
};

class ErrorHandler : public LogHandler 
{
public:
    explicit ErrorHandler(const std::string& filename) : filename_(filename) {}

protected:
    bool canHandle(MessageType type) const override 
    {
        return type == MessageType::Error;
    }
    void process(const LogMessage& msg) override 
    {
        std::ofstream ofs(filename_, std::ios_base::app);
        if (ofs.is_open()) 
        {
            ofs << "Error " << msg.message() << endl;
        }
        else 
        {
            throw std::runtime_error("Невозможно открыть log файл");
        }
    }

private:
    string filename_;
};

class WarningHandler : public LogHandler 
{
protected:
    bool canHandle(MessageType type) const override 
    {
        return type == MessageType::Warning;
    }

    void process(const LogMessage& msg) override 
    {
        cout << "Warning " << msg.message() << endl;
    }
};

class UnknownHandler : public LogHandler 
{
protected:
    bool canHandle(MessageType type) const override { return true; }              // Обрабатываеv остатки    
    void process(const LogMessage& msg) override 
    {
        throw std::runtime_error("Неизвестнвй тип сообщения " + msg.message());
    }
};

int main() 
{
    setlocale(LC_ALL, "russian");
   
    auto fatalHandler = std::make_shared<FatalErrorHandler>();               // обработчики
    auto errorHandler = std::make_shared<ErrorHandler>("errors.log");
    auto warningHandler = std::make_shared<WarningHandler>();
    auto unknownHandler = std::make_shared<UnknownHandler>();

    fatalHandler->setNext(errorHandler);
    errorHandler->setNext(warningHandler);
    warningHandler->setNext(unknownHandler);
   
    LogMessage warningMsg(MessageType::Warning, "Предупреждение");       // сообщения

    try 
    {
        fatalHandler->handle(warningMsg);           // вывод в консоль
               
        LogMessage errorMsg(MessageType::Error, "Ошибка");   // ошибка
        fatalHandler->handle(errorMsg);
       
        LogMessage fatalMsg(MessageType::FatalError, "Fatal Error");   // фатальная ошибка 
        fatalHandler->handle(fatalMsg);        
        cout << "Вывод не выполнен" << endl;         //Не выполнится из-за исключения

    }
    catch (const exception& ex) 
    {       
        cerr << "Обработка остановлена из-за Fatal_Error " << ex.what() << endl;  // Ыывод сообщения и завершение программы
    }
       
}