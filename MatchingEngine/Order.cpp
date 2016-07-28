#include "stdafx.h"
#include "Order.h"




Order::Order(action act, long size, buysell side, double price, ordtype ordertype, long ID):
maction(act), msize(size), mside(side), mprice(price), mordertype(ordertype), mID(ID)
{
}

long Order::ID() { return mID; }
action Order::act() { return maction; }
long Order::size() { return msize; }
buysell Order::side() { return mside; }
double Order::price() { return mprice; }
ordtype Order::ordertype() { return mordertype; }


Order::~Order()
{
}
