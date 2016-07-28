#pragma once
#include "ItemDecor.h"
struct BookEntry
{
public:
	BookEntry(long vol, long ID)
		: mvol(vol), mID(ID), pDecorator(NULL) {}
	long mvol;
	long mID;
	ItemDecorator * pDecorator;

};

