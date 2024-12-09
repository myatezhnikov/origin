#include <iostream>
#include <string>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	
	std::string s = "";
	std::cout << "Введите имя : "; 
	std::cin >> s;
	std::cout << std::endl; std::cout << "Здравствуйте, " << s << "!";
	std::cout << std::endl;
	system("pause");
			
	return 0;
}