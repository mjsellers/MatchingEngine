#include "stdafx.h"
#include "ProcessorFactory.h"


ProcessorFactory::ProcessorFactory(iPublisher& p, iFeedback& f)
	: pub (p), feed(f)
{
	mContinuous = NULL;
}

ProcessorFactory::~ProcessorFactory()
{
	if (mContinuous != NULL)
		delete mContinuous;
}

iMatchProcessor* ProcessorFactory::Get(marketstatus s)
{
	switch (s)
	{
	case continuous:
		if (mContinuous == NULL)
			mContinuous = new ContinuousProcessor(pub, feed);
		return mContinuous;
	case preauction:
	case auction:
	default:
		throw "not implemented";
		return NULL;
	};
}
