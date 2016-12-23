#pragma once

enum class ETestCase
{
	Fibonacci,
	Array,
	DynArray,
	StringBuilder,
	HashMap,
	LinkedList,
};

void RunTest(ETestCase testCase);
