#pragma once

#include "lib/DynArray.h"
#include "lib/LinkedList.h"

namespace Problems
{
	// Description:
	// Eight Queens problem -> https://en.wikipedia.org/wiki/Eight_queens_puzzle
	void SolveEightQueens(CS101::CLinkedList< CS101::CDynArray<int> >& solutions);
	
	struct SKnapsackItem
	{
		SKnapsackItem()
			: weight(0)
			, value(0)
		{
		}
		
		SKnapsackItem(int _weight, int _value)
			: weight(_weight)
			, value(_value)
		{
		}
		
		int weight;
		int value;
	};
	
	// Description
	// Knapsack problem (Recursive) -> https://en.wikipedia.org/wiki/Knapsack_problem
	void SolveKnapsack(const CS101::CDynArray<SKnapsackItem>& items, const int maxWeight, CS101::CDynArray<int>& solution);
	
}
