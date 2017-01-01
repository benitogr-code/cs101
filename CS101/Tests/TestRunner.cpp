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
#include "TestQueue.h"
#include "TestGraph.h"
#include "TestBSTree.h"
#include "TestProblemStrings.h"
#include "TestProblemLinkedLists.h"
#include "TestProblemStacks.h"

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
	case ETestCase::Queue:
		pTest = new CTestQueue();
		break;
	case ETestCase::Graph:
		pTest = new CTestGraph();
		break;
	case ETestCase::BSTree:
		pTest = new CTestBSTree();
		break;
	case ETestCase::ProblemStrings:
		pTest = new CTestProblemStrings();
		break;
	case ETestCase::ProblemLinkedLists:
		pTest = new CTestProblemLinkedLists();
		break;
	case ETestCase::ProblemStacks:
		pTest = new CTestProblemStacks();
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