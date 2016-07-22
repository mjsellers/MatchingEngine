#include "stdafx.h"
#include "ContinuousProcessor.h"



ContinuousProcessor::ContinuousProcessor(iPublisher& p, iFeedback& f)
	: iMatchProcessor (p, f)
{
}


ContinuousProcessor::~ContinuousProcessor()
{
}


int ContinuousProcessor::Process(Order o)
{
	return 1;
}
