#include "stdafx.h"
#include "Order.h"




Order::Order(long size, buysell side, double price, type ordertype, long ID):
size(size), side(side), price(price), ordertype(ordertype), mID(ID)
{
}

long Order::ID()
{
	return mID;
}

Order::~Order()
{
}
