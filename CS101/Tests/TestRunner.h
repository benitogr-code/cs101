#pragma once

enum class ETestCase
{
	Fibonacci,
	Array,
	DynArray,
	StringBuilder,
};

void RunTest(ETestCase testCase);
