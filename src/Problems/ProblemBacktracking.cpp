#include "ProblemBacktracking.h"

#define EIGHT_QUEENS_COUNT 8

namespace Problems
{
	namespace Private
	{
		template<typename T>
		bool IsColumnFree(const CDynArray<T>& board, const T& column)
		{
			for (size_t i = 0; i < board.Size(); ++i)
			{
				if (column == board[i])
					return false;
			}
			
			return true;
		}
		
		void SolveEightQueens(CLinkedList< CDynArray<int>>& solutions,
													CDynArray<int>& board, CDynArray<int>& diagDesc, CDynArray<int>& diagAsc)
		{
			
			if (board.Size() == EIGHT_QUEENS_COUNT)
			{
				solutions.Append(board);
			}
			else
			{
				int currentRow = (int)board.Size();
				for (int i = 1; i <= EIGHT_QUEENS_COUNT; ++i)
				{
					if (!IsColumnFree(board, i) || !IsColumnFree(diagDesc, (i - currentRow)) || !IsColumnFree(diagAsc, (i + currentRow)))
						continue;
					
					board.PushBack(i);
					diagDesc.PushBack(i-currentRow);
					diagAsc.PushBack(i+currentRow);
					
					SolveEightQueens(solutions, board, diagDesc, diagAsc);
					
					board.PopBack();
					diagDesc.PopBack();
					diagAsc.PopBack();
				}
			}
		}
		
		//////////////////////////////////////////
		
		struct SKnapsackHelper
		{
			SKnapsackHelper(int _maxWeight)
				: currentWeight(0)
				, currentValue(0)
				, bestValue(0)
				, maxWeight(_maxWeight)
			{
			}
			
			void AddItem(int idx, int w, int v)
			{
				current.PushBack(idx);
				currentWeight += w;
				currentValue += v;
			}
			
			void PopItem(int w, int v)
			{
				current.PopBack();
				currentWeight -= w;
				currentValue -= v;
			}
			
			void UpdateBestResult()
			{
				if (currentValue <= bestValue)
					return;
				
				bestValue = currentValue;
				best = current;
			}
			
			CDynArray<int> current;
			CDynArray<int> best;
			
			int currentWeight;
			int currentValue;
			
			int bestValue;
			
			const int maxWeight;
		};
		
		void SolveKnapsack(const int itemIdx, const CDynArray<SKnapsackItem>& items, SKnapsackHelper& helper)
		{
			if (itemIdx >= items.Size())
				return;
			
			// 1 - Try adding the current item (if possible)
			const auto& item = items[itemIdx];
			const int newWeight = helper.currentWeight + item.weight;
			if (newWeight <= helper.maxWeight)
			{
				helper.AddItem(itemIdx, item.weight, item.value);
				helper.UpdateBestResult();
				
				// If there is space left, continue exploring
				if (newWeight < helper.maxWeight)
					SolveKnapsack(itemIdx + 1, items, helper);
				
				helper.PopItem(item.weight, item.value);
			}
			
			// 2 - Evaluate without adding the current item
			SolveKnapsack(itemIdx + 1, items, helper);
		}
	}
	
	void SolveEightQueens(CLinkedList< CDynArray<int>>& solutions)
	{
		CDynArray<int> board(EIGHT_QUEENS_COUNT);
		CDynArray<int> diagDesc(EIGHT_QUEENS_COUNT), diagAsc(EIGHT_QUEENS_COUNT);
		
		Private::SolveEightQueens(solutions, board, diagDesc, diagAsc);
	}
	
	void SolveKnapsack(const CDynArray<SKnapsackItem>& items, const int maxWeight, CDynArray<int>& solution)
	{
		Private::SKnapsackHelper helper(maxWeight);
		Private::SolveKnapsack(0, items, helper);
		
		solution = helper.best;
	}
	
}
