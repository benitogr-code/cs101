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
	ProblemStrings,
	ProblemLinkedLists,
	ProblemStacks,
};

void RunTest(ETestCase testCase);
