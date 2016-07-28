#include "stdafx.h"
#include "CppUnitTest.h"
#include "util.h"
#include "Order.h"
#include "ProcessorFactory.h"
#include "Stubs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;



namespace TestMatchingEngine
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CreateOrder)
		{
			Order o(create, 100, buy, 10.1, limit, long(10001));
			Assert::AreEqual(o.ID(), long(10001), 0);
			Assert::AreEqual(long(o.act()), long(create), 0);
			Assert::AreEqual(o.size(), long(100), 0);
			Assert::AreEqual(o.price(), double(10.1), 0);
			Assert::AreEqual(long(o.ordertype()), long(limit), 0);

			string s = string_format("order created %d @ %.2f", o.size(), o.price());
			Logger::WriteMessage(s.c_str());
		}
		TEST_METHOD(ProcessorFactoryTest)
		{
			StubPublisher pub;
			StubFeedback feed;
			feed.Fill(1, 1.2, 10);
			pub.Trades(1.2, 100);
			ProcessorFactory p(pub, feed);
			iMatchProcessor* i = p.Get(continuous);
			string s = string_format("Match processor created [%x]", i);
			Logger::WriteMessage(s.c_str());
			Order o(create, 10, buy, 10.1, limit, 10001);
			Logger::WriteMessage("Order created");
			
			side* buy = new side();
			side* sell = new side();
			orderindex* idx = new orderindex();

			int ret = i->Process(o,buy, sell, idx);
			s = string_format("Processor called and returned [%d]", ret);
			Logger::WriteMessage(s.c_str());

		}
		TEST_METHOD(ValidatorTest)
		{
			StubPublisher pub;
			StubFeedback feed;
			ProcessorFactory fact(pub, feed);
			StubValidator val(fact);
			Order o(create, 100, buy, 10.1, limit, long(10001));
			val.CheckLotsize(o);
			val.CheckTicksize(o);
			iMatchProcessor* processor = val.GetProcessor(o);
			Assert::IsNotNull(processor);
		}		
		TEST_METHOD(OrderBookTest)
		{
			StubPublisher pub;
			StubFeedback feed;
			ProcessorFactory fact(pub, feed);
			StubValidator val(fact);

			OrderBook orderBook(pub, feed, val);
			Order o(create, 100, buy, 10.1, limit, long(10001));
			Assert::IsTrue(orderBook.AddOrder(o));
		}

	};
}