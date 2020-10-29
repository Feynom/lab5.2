#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.2/lab5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			int a = 3;
			t = S(1, 2, a, 4);

			Assert::AreEqual(t, 2, 3, 4);
		}
		TEST_METHOD(TestMethod2)
		{
			double t;
			t = A(1, 2, 3);
			Assert::AreEqual(1, t, 3);
		}
	};
}
