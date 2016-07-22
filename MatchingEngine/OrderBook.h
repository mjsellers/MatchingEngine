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
	int AddOrder();
private:
	side *mBuy;
	side *mSell;

	iPublisher& pub;
	iFeedback& feed;
	iValidator& val;

	map <long, BookEntry*> mIDIndex;



};

