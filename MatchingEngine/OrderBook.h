#pragma once
#include "types.h"
#include "iPublisher.h"
#include "iFeedback.h"
#include "iValidator.h"

class OrderBook
{
public:
	// Constructor takes in Publisher, Feedback and Validator classes
	OrderBook(iPublisher& p, iFeedback& f, iValidator& v);
	virtual ~OrderBook();
	bool AddOrder(Order& o);
private:
	side *mBuy;
	side *mSell;
	orderindex* mIDIndex;

	iPublisher& pub;
	iFeedback& feed;
	iValidator& val;




};

