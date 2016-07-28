#pragma once
#include "iFeedback.h"
#include "iPublisher.h"
#include "iValidator.h"
#include "Order.h"
#include "iMatchProcessor.h"
#include "ProcessorFactory.h"

class StubFeedback : public iFeedback
{
public:
	StubFeedback();
	virtual ~StubFeedback();

	virtual int Status(long ID, status state);
	virtual int Fill(long ID, double price, long volume);
};

class StubPublisher : public iPublisher
{
public:
	StubPublisher();
	virtual ~StubPublisher();

	virtual int Delta(BookEntry& b);
	virtual int Snapshot(side& buy, side& sell);
	virtual int Trades(double price, long volume);
};

class StubValidator : public iValidator
{
public:
	StubValidator(ProcessorFactory& f);
	virtual ~StubValidator();

	virtual int CheckLotsize(Order& o);
	virtual int CheckTicksize(Order& o);
	virtual iMatchProcessor* GetProcessor(Order& o);
private:
	ProcessorFactory& fact;
};
