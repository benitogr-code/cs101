#include "StdAfx.h"
#include "TestProblemBacktracking.h"

#include "Problems/ProblemBacktracking.h"

using namespace CS101;

CTestProblemBacktracking::CTestProblemBacktracking()
	: CBaseTest("Problems Backtracking")
{
}

void CTestProblemBacktracking::Run()
{
	{
		printf("Eight Queens:\n");
	
		CLinkedList< CDynArray<int>> solutions;
		Problems::SolveEightQueens(solutions);
	
		int solCount = 0;
		for (auto pSolution = solutions.Begin(); pSolution != nullptr; pSolution = pSolution->pNext)
		{
			std::string line;
			line.reserve(128);
		
			line.append("\t[ ");
			for (size_t i = 0; i < pSolution->data.Size(); ++i)
			{
				line.append(std::to_string(pSolution->data[i]));
				if (i != pSolution->data.Size() - 1)
					line.append(", ");
			}
			line.append(" ]");
		
			printf("Solution %d - %s\n", ++solCount, line.c_str());
		}
	}
	
	{
		printf("Knapsack (BFS):\n");
		
		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<> wDist(1, 10);
		std::uniform_int_distribution<> vDist(15, 50);
		
		CDynArray<Problems::SKnapsackItem> items;
		for (int i = 0; i < 10; ++i)
		{
			Problems::SKnapsackItem item(wDist(generator), vDist(generator));
			items.PushBack(item);
			
			printf("\tItem %d: Weight = %d, Value = %d\n", i, item.weight, item.value);
		}

		
		const int maxWeight = 21;
		CDynArray<int> solution;
	
		Problems::SolveKnapsack(items, maxWeight, solution);
		
		if (solution.Size() > 0)
		{
			printf("Solution for maxWeight '%d': %d items \n", maxWeight, (int)solution.Size());
			int totalWeight = 0;
			int totalValue = 0;
			for (int i = 0; i < solution.Size(); ++i)
			{
				const auto& item = items[solution[i]];
				totalWeight += item.weight;
				totalValue  += item.value;
				
				printf("\tItem %d: Weight = %d, Value = %d\n", solution[i], item.weight, item.value);
			}
			printf("Total weight = %d, value = %d\n", totalWeight, totalValue);
		}
		else
		{
			printf("No items could be added to the knapsack\n");
		}
	}
	
}
