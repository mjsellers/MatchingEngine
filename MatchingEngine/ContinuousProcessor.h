#pragma once
#include "iMatchProcessor.h"
#include "OrderBook.h"

class ContinuousProcessor :
	public iMatchProcessor
{
public:
	ContinuousProcessor(iPublisher& p, iFeedback& f);
	virtual ~ContinuousProcessor();
	bool Process(Order o, side* buy, side* sell, orderindex* idx);
	bool AddOrderEntry(Order o, side* s, orderindex* idx);

};

