#include "stdafx.h"
#include "OrderBook.h"


OrderBook::OrderBook(iPublisher& p, iFeedback& f, iValidator& v)
	:pub(p), feed(f), val(v)
{
}


OrderBook::~OrderBook()
{
}
