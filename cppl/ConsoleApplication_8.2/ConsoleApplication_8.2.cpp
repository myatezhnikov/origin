#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>

template <typename T>
void print_container(T data)
{	
	for (auto it = data.begin(); it != data.end(); it++)    //выводим на экран через итератор
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set);

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list);

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector);

	std::cout << std::endl;
	system("Pause");
	return 0;
};