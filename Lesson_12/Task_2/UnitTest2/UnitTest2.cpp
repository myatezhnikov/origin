#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication2/extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(Mean)
		try
		{
			ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
			Assert::AreEqual(0.0, v1.mean(5, 2));
			Assert::AreEqual(1.75, v1.mean(1, 4));
		}
		catch (const std::invalid_argument& ia)
		{
			std::cerr << "invalid_argument: " << ia.what() << std::endl;
		};
	};
}