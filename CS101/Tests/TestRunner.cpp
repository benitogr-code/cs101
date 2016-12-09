#include "StdAfx.h"
#include "TestRunner.h"

#include "BaseTest.h"
#include "TestFibonacci.h"

void RunTest(ETestCase testCase)
{
	CBaseTest* pTest = nullptr;
	switch (testCase)
	{
	case ETestCase::Fibonacci:
		pTest = new CTestFibonacci();
		break;
	}

	if (pTest)
	{
		pTest->Setup();
		pTest->Execute();
		pTest->TearDown();

		delete pTest;
		pTest = nullptr;
	}
	else
	{
		printf("RunTest Error: Invalid test case provided.");
	}
}