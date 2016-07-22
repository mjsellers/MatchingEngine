#pragma once

#include "types.h"


class iPublisher
{
public:

	iPublisher()
	{
	}

	virtual ~iPublisher()
	{
	}
	// Send out delta to subscribers
	virtual int Delta(BookEntry& b) = 0;
	// Send out snapshot
	virtual int Snapshot(side& buy, side& sell) = 0;
	// Send out trades
	virtual int Trades(double price, long volume) = 0;
};

