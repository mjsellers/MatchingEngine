#pragma once
#include "iMatchProcessor.h"
class ContinuousProcessor :
	public iMatchProcessor
{
public:
	ContinuousProcessor(iPublisher& p, iFeedback& f);
	virtual ~ContinuousProcessor();
	int Process(Order o);

};

