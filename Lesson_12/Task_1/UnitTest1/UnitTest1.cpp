#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{		
	public:
		TEST_METHOD(Mean) {
			ExtArray<int> v1{}; 
			int x = v1.size();
			Assert::AreEqual(x, 0);
		}
		TEST_METHOD(Median) {
			ExtArray<double> v2{};
			int x = v2.size();
			Assert::AreEqual(x, 0);
		}
		TEST_METHOD(Mode) {
			ExtArray<int> v1{}; 
			int x = v1.size();
			Assert::AreEqual(x, 0);
		}
	};
}