#include "pch.h"
#include "CppUnitTest.h"
#include "../Project3/extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		
		TEST_METHOD(checkSum)
		{
			try
			{
				ExtArray<bool> v1{ 1, 0, 1, 1, 1, 0, 0 };
				Assert::AreEqual(4, v1.checkSum());
				ExtArray<int> v2{ 0, 1, 0, 1, 1, 0, 0, 0 };
				Assert::AreEqual(3, v2.checkSum());
				ExtArray<int> v3{ 4, 1, 0, 1, -5, 0, -3, 1 };
				Assert::AreEqual(0, v3.checkSum());
				ExtArray<double> v4{ 4.0, 2.1, 7.2 };
				Assert::AreEqual(0, v4.checkSum());
				
			}
			catch (const std::bad_typeid& i) 
			{	std::cerr << "bad_typeid" << i.what() << std::endl;	}
			catch (const std::logic_error& i) 
			{	std::cerr << "logic_error" << i.what() << std::endl; }
		}
	};
}
