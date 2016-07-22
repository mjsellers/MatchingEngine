#pragma once
#include "Order.h"
#include "iPublisher.h"
#include "iFeedback.h"

class iMatchProcessor
{
public:

	iMatchProcessor(iPublisher& p, iFeedback& f)
		: pub(p), feed(f)
	{
	}

	virtual ~iMatchProcessor()
	{
	}
	virtual int Process(Order o) = 0;

	iPublisher& pub;
	iFeedback& feed;

};

