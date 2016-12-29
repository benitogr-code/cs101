#include "StdAfx.h"
#include "TestProblemStacks.h"

#include "Problems/ProblemStacks.h"

CTestProblemStacks::CTestProblemStacks()
	: CBaseTest("Problems: Stacks")
{
}

void CTestProblemStacks::Run()
{
	CS101::CStack<int> stack1;
	stack1.Push(3);
	stack1.Push(2);
	stack1.Push(5);
	stack1.Push(1);
	stack1.Push(4);

	printf("Sorting stack of integers:\n");

	Problems::SortStack(stack1);

	while (!stack1.Empty())
	{
		printf("\t%d\n", stack1.Pop());
	}

	CS101::CStack<std::string> stack2;
	stack2.Push("airfield");
	stack2.Push("crystadium");
	stack2.Push("bluelagoon");
	stack2.Push("yellowpier");
	stack2.Push("redtower");

	printf("\nSorting stack of strings:\n");

	Problems::SortStack(stack2);

	while (!stack2.Empty())
	{
		printf("\t%s\n", stack2.Pop().c_str());
	}
}