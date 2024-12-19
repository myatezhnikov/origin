#include <iostream>
#include "extended_array.h"

int main()
{
    try
    {
        ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
        std::cout << v1.mean(2, 3) << std::endl;
        system("Pause");
        std::cout << v1.mean(4, 1);
    }
    catch (const std::invalid_argument& i)
    {
        std::cerr << "invalid_argument: " << i.what() << std::endl;
        system("Pause");
    }
}