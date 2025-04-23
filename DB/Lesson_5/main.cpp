#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <string>
#include <memory>

using namespace std;

class ClientManager
{
public: 
     
    ClientManager(string host, string port, string dbname, string user, string password)
        : connect("host=" + host + " port=" + port + " dbname=" + dbname + " user=" + user + " password=" + password)
    {
        create_Tables(); // В private создаем таблицы при паервом подключении         
                   
    }
      void add_Client(string firstname, string surname, string email) //функция добавления клиента
      {  
          pqxx::work tx(connect);
          tx.exec_prepared("add_client", firstname, surname, email);
          tx.commit();
      }
      void add_phone(string firstname, string surname, string number)  //функция добавления телефона
      {   
          pqxx::work tx(connect);
          tx.exec_prepared("add_phone", firstname, surname, number);
          tx.commit();
      }
      void update_clients(string firstname, string surname, string email)   //функция обновления клиента
      {    
          pqxx::work tx(connect);
          tx.exec_prepared("update_clients", firstname, surname, email);
          tx.commit();
      }
      void delete_phone_number(string firstname, string surname)        //функция удаения телефона клиента
      {     
          pqxx::work tx(connect);
          tx.exec_prepared("delete_phone", firstname, surname);
          tx.commit();
      }
      void delete_client(string firstname, string surname)      //функция удаления клиента
      {      
          pqxx::work tx(connect);
          tx.exec_prepared("delete_client", firstname, surname);
          tx.commit();
      }
      void find_client(string find_text)                //функция поиска клиента
      {        
          pqxx::work tx(connect);
          auto res = tx.query<string, string, string>(
              "select firstname, surname, email from clients c "
              "join phone_numbers pn on c.id_client = pn.id_client where "
              "(c.firstname LIKE $1) OR (c.surname LIKE $1) OR (c.email LIKE $1) "
              "OR (pn.p_number LIKE $1);", find_text);             
          if (res.begin() == res.end()) cout << "Client not find" << endl;  //если результат запроса пустота

          for (const auto [firstname, surname, email] : res) {              //если чтл-то нашли             
              cout << firstname << " " << surname << " " << email << " " << endl;
          }
         
      }

      ~ClientManager(){}

private:   
    pqxx::connection connect;    

    void create_Tables()
    {
        pqxx::work tx(connect);
        //Создаем таблицы
        /*Таблица клиенты*/
        tx.exec("CREATE TABLE IF NOT EXISTS clients ("
            "id_client serial UNIQUE NOT NULL, "
            "firstname VARCHAR(60) NOT NULL, "
            "surname VARCHAR(60) NOT NULL, "
            "email VARCHAR(60), "
            "CONSTRAINT pk_clients PRIMARY KEY(firstname, surname));");

        /*Таблица телефонов*/
        tx.exec("CREATE TABLE IF NOT EXISTS phone_numbers("
            "id_client integer references clients(id_client), "
            "p_number VARCHAR(12), "
            "CONSTRAINT pk_clients_phone_numbers PRIMARY KEY(id_client, p_number));");
        tx.commit();

        //Создаем шаблоны запросов prepare
        connect.prepare("add_client",
            "INSERT INTO clients(firstname, surname, email) VALUES ($1, $2, $3);");   //Добавление клиента

        connect.prepare("add_phone",
            "INSERT INTO phone_numbers(id_client, p_number) values "            //Добавление телефона
            "((SELECT id_client from clients where firstname = $1 and surname = $2), $3);");

        connect.prepare("update_clients",
            "UPDATE clients SET firstname = $1, "           //Обновление данных о клиенте
            "surname = $2, email=$3 "
            "WHERE(firstname = $1) AND(surname = $2);");

        connect.prepare("delete_phone",                             //Удаление телефона клиента
            "delete from phone_numbers where id_client = "
            "(SELECT id_client from clients "
            "WHERE(firstname = $1) AND(surname = $2));");

        connect.prepare("delete_client",
            "delete from clients where (firstname = $1) AND(surname = $2);");//Удаление клиента
    }
};
int main()
{
    // Устанавливаем кодировку консоли
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    try
    {           
        auto CM = make_unique<ClientManager>("localhost", "5432", "client_manager", "postgres", "432029");      
      
        CM->add_Client("Jhon", "First", "mail2@mail.ru");
        CM->add_phone("Jhon", "First", "+79278562053");
        CM->find_client("%927%");
      
    }
    catch (pqxx::sql_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    system("Pause");
    return 0;
}