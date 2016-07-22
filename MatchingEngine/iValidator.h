#pragma once
#include "Order.h"
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
	virtual int CheckMarketStatus(Order& o) = 0;

};

