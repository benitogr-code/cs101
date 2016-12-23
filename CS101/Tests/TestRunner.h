#pragma once

enum class ETestCase
{
	Fibonacci,
	Array,
	DynArray,
	StringBuilder,
	HashMap,
	LinkedList,
	ProblemStrings,
};

void RunTest(ETestCase testCase);
