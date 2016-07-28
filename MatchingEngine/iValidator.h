#pragma once
#include "Order.h"
#include "iMatchProcessor.h"

class iValidator
{
public:

	iValidator()
	{
	}
	virtual ~iValidator()
	{
	}
	virtual int CheckLotsize(Order& o) = 0;
	virtual int CheckTicksize(Order& o) = 0;
	virtual iMatchProcessor* GetProcessor(Order& o) = 0;
};

