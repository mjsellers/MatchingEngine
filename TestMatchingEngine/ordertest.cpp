#include "stdafx.h"
#include "CppUnitTest.h"
#include "Order.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMatchingEngine
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CreateOrder)
		{
			Order o(100, buy, 10.1, limit, 10001);
			double l = 0;
			l = o.ID();
			Assert::AreEqual(l, (double)10001, 0);
			
		}

	};
}