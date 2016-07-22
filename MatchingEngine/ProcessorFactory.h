#pragma once
#include "iPublisher.h"
#include "iFeedback.h"
#include "OrderBook.h"
#include "iMatchProcessor.h"
#include "ContinuousProcessor.h"

enum marketstatus 
{ continuous = 0, preauction = 1, auction = 2 };
class ProcessorFactory
{
public:
	ProcessorFactory(iPublisher& p, iFeedback& f);
	~ProcessorFactory();
	iMatchProcessor* Get(marketstatus s);
private:
	iPublisher& pub;
	iFeedback& feed;
	ContinuousProcessor *mContinuous;
};

