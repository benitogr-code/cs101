#include "StdAfx.h"
#include "TestStack.h"

#include "CS101/Stack.h"

CTestStack::CTestStack()
	: CBaseTest("Stack")
{
}

void CTestStack::Run()
{
	CS101::CStack<std::string> stack;
	stack.Push("Item 01");
	stack.Push("Item 02");
	stack.Push("Item 03");
	stack.Push("Item 04");
	stack.Push("Item 05");

	printf("Inspecting stack... (Early peek = '%s')\n\n", stack.Peek().c_str());
	while (!stack.Empty())
	{
		printf("\t%s\n", stack.Pop().c_str());
	}
}