#include "stdafx.h"
#include "OrderBook.h"


OrderBook::OrderBook(iPublisher& p, iFeedback& f, iValidator& v)
	:pub(p), feed(f), val(v)
{
	mBuy = new side();
	mSell = new side();
	mIDIndex = new orderindex();
	
}


OrderBook::~OrderBook()
{
}

bool OrderBook::AddOrder(Order& o)
{
	val.CheckLotsize(o);
	val.CheckTicksize(o);
	iMatchProcessor* proc = val.GetProcessor(o);
	bool ret = proc->Process(o, mBuy, mSell, mIDIndex);

	return ret;
}
