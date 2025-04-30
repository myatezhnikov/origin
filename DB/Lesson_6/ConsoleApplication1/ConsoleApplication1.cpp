
#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>

using namespace std;
using namespace Wt;

class Book;
class Stock;
class Sale;

class Publisher
{
public:
		string name = "";
		Dbo::collection<Dbo::ptr<Book>> books;		//коллекция из книг

		template<class Action>
		void persist(Action& a)
		{
			Dbo::field(a, name, "name");
			Dbo::hasMany(a, books, Dbo::ManyToOne, "id_publisher");			//связь один ко многим
		}
};

class Book
{
public:
	string title = "";
	Dbo::ptr<Publisher> publisher;
	Dbo::collection<Dbo::ptr<Stock>> stock;		//коллекция из stock

	template<class Action>
	void persist(Action& a)
	{
		Dbo::field(a, title, "title");
		Dbo::belongsTo(a, publisher, "id_publisher");
		Dbo::hasMany(a, stock, Dbo::ManyToOne, "id_book");		//связь один ко многим 
	}
};

class Shop
{
public:
	string name = "";
	Dbo::collection<Dbo::ptr<Stock>> stock;

	template<class Action>
	void persist(Action& a)
	{
		Dbo::field(a, name, "name");
		Dbo::hasMany(a, stock, Dbo::ManyToOne, "id_shop");		//связь один ко мнгоим 
	}
};

class Stock
{
public:
	int count = 0;
	Dbo::ptr<Book> book;
	Dbo::ptr<Shop> shop;
	Dbo::collection<Dbo::ptr<Sale>> sale;

	template<class Action>
	void persist(Action& a)
	{
		Dbo::field(a, count, "count");
		Dbo::belongsTo(a, shop, "id_shop");
		Dbo::belongsTo(a, book, "id_book");
		Dbo::hasMany(a, sale, Dbo::ManyToOne, "id_stock");		//связь один ко мнгоим 
	}

	
};

class Sale
{
public:
	float price = 0;
	string date_sale = "";
	int count = 0;
	Dbo::ptr<Stock> stock;

	template<class Action>
	void persist(Action& a)
	{
		Dbo::field(a, price, "price");
		Dbo::field(a, date_sale, "date_sale");
		Dbo::belongsTo(a, stock, "id_stock");
		Dbo::field(a, count, "count");
	}
};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//setlocale(LC_ALL, "Russian");

	try
	{
		std::string connectionString =
			"host=localhost "
			"port=5432 "
			"dbname=books "
			"user=postgres "
			"password=432029";
		
		auto postgres = make_unique<Dbo::backend::Postgres>(connectionString);
		Dbo::Session session;
		session.setConnection(move(postgres));					// создаем таблицы
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Stock>("stock");
		session.mapClass<Shop>("shop");
		session.mapClass<Sale>("sale");
		session.createTables();

		Dbo::Transaction transaction0(session);		//обозначение уникальных ключей
		session.execute("ALTER TABLE publisher ADD CONSTRAINT unique_publisher_name UNIQUE (name)");
		session.execute("ALTER TABLE book ADD CONSTRAINT unique_book_title UNIQUE (title)");
		session.execute("ALTER TABLE shop ADD CONSTRAINT unique_shop_name UNIQUE (name)");
		transaction0.commit();
		
		//Добавление данных в таблицу
		Dbo::Transaction transaction1(session);
		{
			Dbo::ptr<Publisher> publisher1 = session.add(std::unique_ptr<Publisher>{new Publisher()}); //добавляем издателя 1
			publisher1.modify()->name = "Publisher_1";
			Dbo::ptr<Publisher> publisher2 = session.add(std::unique_ptr<Publisher>{new Publisher()}); //добавляем издателя 2
			publisher2.modify()->name = "Publisher_2";

			Dbo::ptr<Shop> shop1 = session.add(unique_ptr<Shop>{new Shop()});	//добавляем магазин 1
			shop1.modify()->name = "Shop_1";
			Dbo::ptr<Shop> shop2 = session.add(unique_ptr<Shop>{new Shop()});	//добавляем магазин 2
			shop2.modify()->name = "Shop_2";
		}
		transaction1.commit();
		
		Dbo::Transaction transaction2(session);
		{
			Dbo::ptr<Book> book = session.add(make_unique<Book>()); //добавляем книгу 1			
			book.modify()->title = "Book_1";
			auto publisher_1 = session.load<Publisher>(1); // берем первую запись
			book.modify()->publisher = publisher_1; //связываем с первой книгой первого издателя

			Dbo::ptr<Book> book1 = session.add(make_unique<Book>()); //добавляем книгу 2			
			book1.modify()->title = "Book_2";
			book1.modify()->publisher = publisher_1; //связываем с первой книгой первого издателя
		}
		transaction2.commit();
		
		Dbo::Transaction transaction3(session);		//заносим данные в stock
		{
			auto stock = session.add(make_unique<Stock>());
			stock.modify()->count = 5;
			stock.modify()->book = session.load<Book>(1);
			stock.modify()->shop = session.load<Shop>(1);

			auto stock1 = session.add(make_unique<Stock>());
			stock1.modify()->count = 10;
			stock1.modify()->book = session.load<Book>(2);
			stock1.modify()->shop = session.load<Shop>(2);

			transaction3.commit();
		}
		Dbo::Transaction transaction4(session);				//заносим данные в sale
		{	
			auto sale = session.add(make_unique<Sale>());
			sale.modify()->stock = session.load<Stock>(1);
			sale.modify()->count = 5;
			sale.modify()->date_sale = "2025-02-05";
			sale.modify()->price = 5.7;

			auto sale1 = session.add(make_unique<Sale>());
			sale1.modify()->stock = session.load<Stock>(2);
			sale1.modify()->count = 10;
			sale1.modify()->date_sale = "2025-03-22";
			sale1.modify()->price = 4.3;
		}
		transaction4.commit();
		
		//Работа с заполненной БД
		string str;
		cout << "Insert name or ID publisher: ";		//Вводим имя или ID
		cin >> str;
		int id=0;

		try
		{
			id = stoi(str);		//Преобразуем строку в число, если это действительно ID
		}
		catch (exception& e)
		{
			//если ошибка преобразования, то ничего не выводим, если это не число, ищем по имени (текст)
		}
		
		Dbo::Transaction transaction5(session);
		{
			auto publishers = session.find<Publisher>()	//находим издателя по имени или id
				.where("name = ? OR id = ?")
				.bind(str)
				.bind(id)
				.resultList();	//коллекция издателей из одного (т.к. имя уникально)

		if (publishers.empty())		//если не нашли издателя
		{ 
			cout << "There is no publishers" << endl;
		}
		else
			for (const auto& publisher : publishers)						//проходим по издателям (он один)
			{	
				if (publisher->books.empty()) 
				{ 
					cout << "Books not found : " << endl;	//если нет такого выводим сообщение
				} 
				else
					for (const auto& book : publisher->books)			//перебираем все книги	
					{					
						if (!book) 
						{							
							continue;
						}
						if (book->stock.empty())
						{
							cout << "Books is not in stock : " << book->title << endl;
							continue; // Переходим к следующей книге если есть
						} 
						else									
							for (const auto& stock : book->stock)		// Для каждой книги проверим (stock)
							{
								if (!stock)
								{
									continue;
								}
								cout << stock->shop->name << endl;
							}
					}
			}
		}
		//transaction5.commit();
	}


	catch (const Dbo::Exception& e)
	{
		cout << e.what() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

}

