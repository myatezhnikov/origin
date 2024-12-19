#include<iostream>
#include"extended_array.h"

int main()
{
	try
	{
		ExtArray<bool> v1{0, 1, 0, 1, 1, 0, 0, 0};		
		std::cout << v1.checkSum() << std::endl;
		ExtArray<int> v2{0, 1, 0, 1, 1, 0, 0, 0};
		std::cout << v2.checkSum() << std::endl;
		ExtArray<int> v3{4, 1, 0, 1, -5, 0, -3, 1};
		std::cout << v3.checkSum() << std::endl;
		ExtArray<double> v4{4.0, 2.1, 7.2};
		std::cout << v4.checkSum() << std::endl;
		return 0;
	}
	catch (const std::bad_typeid& i) { std::cerr << "Wrong Type: " << i.what() << std::endl;	}
	catch (const std::logic_error& i) { std::cerr << "logic_error: " << i.what() << std::endl; }
}