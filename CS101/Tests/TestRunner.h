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
	ProblemStrings,
	ProblemLinkedLists,
};

void RunTest(ETestCase testCase);
