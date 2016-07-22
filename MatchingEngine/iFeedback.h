#pragma once

enum status
{
	open = 0, partial = 1, filled = 2, cancelled = 3, amendaccept = 4, amendreject = 5
};

class iFeedback
{
public:
	iFeedback::iFeedback()
	{
	}
	virtual iFeedback::~iFeedback()
	{
	}
	virtual int Status(long ID, status state) = 0;
	virtual int Fill(long ID, double price, long volume) = 0;
};

