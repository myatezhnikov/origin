#include<iostream>
#include"extended_array.h"

int main()
{
	ExtArray<int> v1{}, v2{ 1, 5 ,6 - 7 };	
	std::cout << v1.size() << std::endl << v2.size() << std::endl;
	system("Pause");
}