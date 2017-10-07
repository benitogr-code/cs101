#pragma once

#include "BaseTest.h"

class CTestMTQueue : public CBaseTest
{
public:
	CTestMTQueue()
		: CBaseTest("MT Queue")
	{}
	
protected:
	virtual void Run() override;
};
