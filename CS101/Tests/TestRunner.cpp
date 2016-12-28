#include "StdAfx.h"
#include "TestRunner.h"

#include "BaseTest.h"
#include "TestFibonacci.h"
#include "TestArray.h"
#include "TestDynArray.h"
#include "TestStringBuilder.h"
#include "TestHashMap.h"
#include "TestLinkedList.h"
#include "TestStack.h"
#include "TestProblemStrings.h"

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
	case ETestCase::StringBuilder:
		pTest = new CTestStringBuilder();
		break;
	case ETestCase::HashMap:
		pTest = new CTestHashMap();
		break;
	case ETestCase::LinkedList:
		pTest = new CTestLinkedList();
		break;
	case ETestCase::Stack:
		pTest = new CTestStack();
		break;
	case ETestCase::ProblemStrings:
		pTest = new CTestProblemStrings();
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