#pragma once

enum class ETestCase
{
	Fibonacci,
	Array,
	DynArray,
	StringBuilder,
	HashMap,
	LinkedList,
	Stack,
	Queue,
	Graph,
	BSTree,
	ProblemStrings,
	ProblemLinkedLists,
	ProblemStacks,
	ProblemBits,
};

void RunTest(ETestCase testCase);
