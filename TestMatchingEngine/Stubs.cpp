#include "stdafx.h"
#include "CppUnitTest.h"
//#include "util.h"
#include "Stubs.h"
#include "ProcessorFactory.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

StubFeedback::StubFeedback() {}
StubFeedback::~StubFeedback(){}
int StubFeedback::Status(long ID, status state)
{
	string s = string_format("Status: order ID=%d in state %s", ID, state);
	Logger::WriteMessage(s.c_str());
	return 0;
}
int StubFeedback::Fill(long ID, double price, long volume)
{
	string s = string_format("Fill: order ID=%d %d@%.2f", ID, volume, price);
	Logger::WriteMessage(s.c_str());
	return 0;
}

StubPublisher::StubPublisher() {}
StubPublisher::~StubPublisher() {}
int StubPublisher::Delta(BookEntry& b)
{
	return 0;
}
int StubPublisher::Snapshot(side& buy, side& sell)
{
	return 0;
}
int StubPublisher::Trades(double price, long volume)
{
	string s = string_format("Trades: %d@%.2f", volume, price);
	Logger::WriteMessage(s.c_str());
	return 0;

}

StubValidator::StubValidator(ProcessorFactory& f) : fact(f)
{
 // Load up the config needed to validate the orders and work out the market phase
}
StubValidator::~StubValidator() {}

int StubValidator::CheckLotsize(Order& o)
{
	string s = string_format("Checked order has round lot %d", o.size());
	Logger::WriteMessage(s.c_str());
	return 0;

}
int StubValidator::CheckTicksize(Order& o)
{
	string s = string_format("Checked order has correct tick size %.2f", o.price());
	Logger::WriteMessage(s.c_str());
	return 0;

}
iMatchProcessor* StubValidator::GetProcessor(Order& o)
{
	// Check time on the order against the market phases in the config for this market
	// and return the correct match processor - in this stub return continuous processor
	iMatchProcessor* proc = fact.Get(continuous);
	string s = string_format("Got processor from factory [%x]", proc);
	Logger::WriteMessage(s.c_str());
	return proc;
}
