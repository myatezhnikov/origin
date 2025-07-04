#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class Observer 
{
public:
    virtual ~Observer() = default;
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class Observable 
{
public:  
    void addObserver(Observer* observer)              // наблюдатель
    {        
        observers_.push_back(observer);
    }  
    void removeObserver(Observer* observer)           // удаление наблюдателя
    {
        observers_.erase(remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }       
    void warning(const string& message) const      //для оповещения warning
    {
        notify(&Observer::onWarning, message);
    }
    void error(const string& message) const         //для оповещения error
    {
        notify(&Observer::onError, message);
    }
    void fatalError(const string& message) const    //для оповещения fatalError
    {
        notify(&Observer::onFatalError, message);
    }

private:
    vector<Observer*> observers_;
   
    void notify(void (Observer::* method)(const string&), const string& message) const     // уведомление
    {
        for (auto* obs : observers_) 
        {
            if (obs != nullptr) 
            {
                (obs->*method)(message);
            }
        }
    }
};

class WarningLogger : public Observer 
{
public:
    void onWarning(const string& message) override {
        cout << "Warning " << message << endl;
    }
};

class ErrorLogger : public Observer {
public:
    explicit ErrorLogger(const std::string& filename) : filename_(filename) {}

    void onError(const string& message) override 
    {
        ofstream ofs(filename_, ios_base::app);
        if (ofs.is_open()) 
        {
            ofs << "Error" << message << std::endl;
        }      
    }

private:
    string filename_;
};

class FatalErrorLogger : public Observer 
{
public:
    explicit FatalErrorLogger(const std::string& filename) : filename_(filename) {}

    void onFatalError(const std::string& message) override 
    {      
        cout << "Fatal_Error " << message << endl;                 // на консоль       
        ofstream ofs(filename_, ios_base::app);                  // в файл
        if (ofs.is_open()) 
        {
            ofs << "Fatal_Error " << message << endl;
        }       
    }

private:
    string filename_;
};

int main() 
{
    Observable logger;

    WarningLogger warningObs;
    ErrorLogger errorObs("Error.log");
    FatalErrorLogger fatalObs("FatalError.log");

    logger.addObserver(&warningObs);
    logger.addObserver(&errorObs);
    logger.addObserver(&fatalObs);

    logger.warning("Warning");
    logger.error("Error");
    logger.fatalError("Fatal_Error");

}