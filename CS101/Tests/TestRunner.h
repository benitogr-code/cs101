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
	ProblemStrings,
};

void RunTest(ETestCase testCase);
