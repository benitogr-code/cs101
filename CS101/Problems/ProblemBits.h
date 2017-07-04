#pragma once

namespace Problems
{
	// Description:
	// Given N and M integers, insert M bits into [i,j] bits
	// N is supposed to have as many bits as j-i
	int Insert(int N, int M, int i, int j);

	// Description:
	// Given A and B integers, calculate how many bits we have to swap
	// to make A == B
	int BitSwapRequired(int A, int B);
}
