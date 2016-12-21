#include "StdAfx.h"
#include "TestRunner.h"

#include "BaseTest.h"
#include "TestFibonacci.h"
#include "TestArray.h"
#include "TestDynArray.h"

void RunTest(ETestCase testCase)
{
	CBaseTest* pTest = nullptr;
	switch (testCase)
	{
	case ETestCase::Fibonacci:
		pTest = new CTestFibonacci();
		break;
	case ETestCase::Array:
		pTest = new CTestArray();
		break;
	case ETestCase::DynArray:
		pTest = new CTestDynArray();
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