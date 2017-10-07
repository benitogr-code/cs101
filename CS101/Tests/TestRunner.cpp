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
#include "TestMTQueue.h"
#include "TestGraph.h"
#include "TestBSTree.h"
#include "TestAVLTree.h"
#include "TestMinHeap.h"
#include "TestSorting.h"
#include "TestUtils.h"
#include "TestBigInt.h"
#include "TestProblemStrings.h"
#include "TestProblemLinkedLists.h"
#include "TestProblemStacks.h"
#include "TestProblemBits.h"
#include "TestProblemBacktracking.h"

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
	case ETestCase::MTQueue:
		pTest = new CTestMTQueue();
		break;
	case ETestCase::Graph:
		pTest = new CTestGraph();
		break;
	case ETestCase::BSTree:
		pTest = new CTestBSTree();
		break;
	case ETestCase::AVLTree:
		pTest = new CTestAVLTree();
		break;
	case ETestCase::MinHeap:
		pTest = new CTestMinHeap();
		break;
	case ETestCase::Sorting:
		pTest = new CTestSorting();
		break;
	case ETestCase::Utils:
		pTest = new CTestUtils();
		break;
	case ETestCase::BigInt:
		pTest = new CTestBigInt();
		break;
	case ETestCase::ProblemStrings:
		pTest = new CTestProblemStrings();
		break;
	case ETestCase::ProblemLinkedLists:
		pTest = new CTestProblemLinkedLists();
		break;
	case ETestCase::ProblemStacks:
		pTest = new CTestProblemStacks();
		break;
	case ETestCase::ProblemBits:
		pTest = new CTestProblemBits();
		break;
	case ETestCase::ProblemBackTracking:
		pTest = new CTestProblemBacktracking();
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
