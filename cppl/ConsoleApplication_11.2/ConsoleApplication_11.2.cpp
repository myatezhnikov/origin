#include <iostream>
#include <string>

struct big_integer 
{
	std::string string; 

public:	
	big_integer(const std::string& str) : string(str)	// Конструктор
	{
		std::reverse(string.begin(), string.end()); // разворачиваем строку в обратный порядок
	}
		
	big_integer(big_integer&& other) noexcept : string(std::exchange(other.string, nullptr)) // конструктор перемещенияc
	{
	}	
	big_integer& operator=(big_integer&& other) noexcept // оператор перемещающего присваивания
	{
		if (this != &other)
		{
			string = std::move(other.string);
			std::cout << string;
		}
		return *this;
	}
	
	big_integer operator+(const big_integer& other) const			// Оператор сложения
	{
		std::string total;
		int ostatok = 0; //переменная для остатка при сложении
		size_t size = std::max(string.size(), other.string.size()); //находим самое длинное число, его кол-во разрядов

		for (size_t i = 0; i < size || ostatok; ++i) 
		{
			//проверяем, если кол-во разрядов меньше, чем size, то вставляем 0
			int d1 = (i < string.size()) ? string[i] - '0' : 0; //переводим из символа в число отнимая 48 = char '0'
			int d2 = (i < other.string.size()) ? other.string[i] - '0' : 0; // тоже самое для второго числа
			int sum = d1 + d2 + ostatok;	//суммируем числа и добавляем остаток, если он есть от предыдущего сложения
			ostatok = sum / 10; //находим остаток, который добавляем к следующему числу
			total.push_back((sum % 10) + '0'); // обратно переводим в символ и вставляем в строку целое число			
		}
		std::reverse(total.begin(), total.end()); // разворачиваем обртано строку для вывода		
		return big_integer(total); // выводим полученное число
	}	

	big_integer operator*(const int& number) const			// Оператор умножения на число
	{
		std::string total;
		int ostatok = 0; //переменная для остатка при сложении
		size_t size = string.size(); // находим размер (кол-во разрядов) числа
		for (size_t i = 0; i < size || ostatok; ++i)
		{
			int mult=0;							
			if (i >= size)						//если при умножении число стало больше на один разряд, т.е. на ostatok
			{ 
				mult = ostatok; 
			}	
			else								//если кол-во разрядов после умножения не меняется 
			{
				mult = (string[i] - '0') * number + ostatok;	//умножаем числа и добавляем остаток, если он есть от предыдущего действия
			}
			ostatok = mult / 10; //находим остаток, который добавляем к следующему числу
			total.push_back((mult % 10) + '0'); // обратно переводим в символ и вставляем в строку целое число				
		}
		std::reverse(total.begin(), total.end()); // разворачиваем обртано строку для вывода
		return big_integer(total); // выводим полученное число
	}
};

std::ostream& operator << (std::ostream& os, const big_integer& other) //переопределяем оператор вывода для big_integer result
{
	return os << std::string(other.string.rbegin(), other.string.rend());
}

int main() {
	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");
	auto result = number1 + number2;
	std::cout << result; // 193099

	std::cout << std::endl << result * 2; // 386198
	std::cout << std::endl;
	system("Pause");
}