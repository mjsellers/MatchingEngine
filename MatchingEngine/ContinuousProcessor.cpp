#include "stdafx.h"
#include "ContinuousProcessor.h"
#include "types.h"

using namespace std;

ContinuousProcessor::ContinuousProcessor(iPublisher& p, iFeedback& f)
	: iMatchProcessor (p, f)
{
}


ContinuousProcessor::~ContinuousProcessor()
{
}

bool ContinuousProcessor::AddOrderEntry(Order o, side* s, orderindex* idx)
{
	BookEntry* entry = new BookEntry(o.size(), o.ID());
	if (o.ordertype() == iceberg)
	{
		// TODO: Add the necessary item decorator to implement the iceberg logic
	}

	side::iterator iter = s->find(o.price());
	if (iter == s->end())
	{
		// insert a new queue level for this price and add the new entry
		queue<BookEntry>* level = new queue<BookEntry>;
		level->push(*entry);
		s->insert({o.price(), level});
	}
	else
	{
		// push the new entry onto the end of the price level queue
		iter->second->push(*entry);
	}

	//Add the index entry for looking up amendments and cancels -
	//ignore zero IDs which are from market data rather than orders
	if (o.ID() != 0)
	{
		orderindex::iterator iter2 = idx->find(o.ID());
		if (iter2 != idx->end())
		{
			// TODO: error handling for duplicate order ID
		}
		else
		{
			idx->insert({ o.ID(), entry });
		}

	}
	return false;
}


bool ContinuousProcessor::Process(Order o, side* buybook, side* sellbook, orderindex* idx)
{
	
	double topPrice;
	side::iterator iter;
	// Test if crossing
	if (o.side() == buy)
	{
		if (sellbook->size() > 0)
		{
			iter = sellbook->begin();
			topPrice = iter->first;
			if (o.price() >= topPrice)
			{
				// Perform crossing
			}
			else
			{
				AddOrderEntry(o, buybook, idx);
			}
		}
		else
		{
			AddOrderEntry(o, buybook, idx);
		}
	}
	else
	{
		if (buybook->size() > 0)
		{
			iter = buybook->end();
			topPrice = iter->first;
			if (o.price() <= topPrice)
			{
				// Perform crossing
			}
			else
			{
				AddOrderEntry(o, sellbook, idx);
			}
		}
		else
		{	
			AddOrderEntry(o, sellbook, idx);
		}
	}
	
	return true;
}
