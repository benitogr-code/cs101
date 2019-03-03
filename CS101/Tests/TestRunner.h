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
	MTQueue,
	BSTree,
	AVLTree,
	MinHeap,
	Sorting,
	Utils,
	Trie,
	BigInt,
	ProblemStrings,
	ProblemLinkedLists,
	ProblemStacks,
	ProblemBits,
	ProblemBackTracking
};

void RunTest(ETestCase testCase);
