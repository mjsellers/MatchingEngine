#pragma once

enum buysell
{
	buy = 0, sell = 1
};
enum ordtype
{
	limit, market, fok, elim, iceberg
};
enum action
{
	create, amend, cancel
};


class Order
{
public:
	Order(action act, long size, buysell side, double price, ordtype ordertype, long ID);
	action act();
	long size();
	buysell side();
	double price();
	ordtype ordertype();
	long ID(); 
	virtual ~Order();
private:
	action maction;
	long msize;
	buysell mside;
	double mprice;
	ordtype mordertype;
	long mID;




};

