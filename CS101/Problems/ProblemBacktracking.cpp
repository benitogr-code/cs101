#include "StdAfx.h"
#include "ProblemBacktracking.h"

using namespace CS101;

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
				int currentRow = board.Size();
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
	}
	
	void SolveEightQueens(CLinkedList< CDynArray<int>>& solutions)
	{
		CDynArray<int> board(EIGHT_QUEENS_COUNT);
		CDynArray<int> diagDesc(EIGHT_QUEENS_COUNT), diagAsc(EIGHT_QUEENS_COUNT);
		
		Private::SolveEightQueens(solutions, board, diagDesc, diagAsc);
	}
}
