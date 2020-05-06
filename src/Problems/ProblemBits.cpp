#include "pch.h"
#include "ProblemBits.h"

namespace Problems
{
	int Insert(int N, int M, int i, int j)
	{
		int result = N;

		// Clear bits [i,j]
		for (int bit = i; bit <= j; ++bit)
		{
			int mask = ~(1 << bit);
			result &= mask;
		}

		// Shift M to align bits
		M = M << i;

		// Merge
		return (result | M);
	}

	int BitSwapRequired(int A, int B)
	{
		int count = 0;

		int c = A ^ B;
		while (c != 0)
		{
			count += (c & 1);
			c = c >> 1;
		}

		return count;
	}
}