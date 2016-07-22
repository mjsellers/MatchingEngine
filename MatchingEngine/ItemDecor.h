#pragma once
class ItemDecorator
{
public:

	ItemDecorator()
	{
	}

	virtual ~ItemDecorator()
	{
	}
	virtual int Process() = 0;
};

