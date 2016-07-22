#pragma once

enum buysell
{
	buy = 0, sell = 1
};
enum type
{
	limit, market, fok, elim
};


class Order
{
public:
	Order(long size, buysell side, double price, type ordertype, long ID);
	long ID();
	virtual ~Order();
private:
	long size;
	buysell side;
	double price;
	type ordertype;
	long mID;




};

