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
	AVLTree,
	MinHeap,
	Sorting,
	Utils,
	BigInt,
	ProblemStrings,
	ProblemLinkedLists,
	ProblemStacks,
	ProblemBits,
	ProblemBackTracking
};

void RunTest(ETestCase testCase);
