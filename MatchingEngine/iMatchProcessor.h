#pragma once
#include "Order.h"
#include "iPublisher.h"
#include "iFeedback.h"
#include "types.h"

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
	virtual bool Process(Order o, side* buy, side* sell, orderindex* idx) = 0;

private:
	iPublisher& pub;
	iFeedback& feed;

};

