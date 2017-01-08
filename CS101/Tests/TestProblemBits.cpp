#include "StdAfx.h"
#include "TestProblemBits.h"

#include "Problems/ProblemBits.h"

CTestProblemBits::CTestProblemBits()
	: CBaseTest("Problems: Bits")
{

}

void CTestProblemBits::Run()
{
	const int N = 128;
	const int M = 14;

	printf("Insert %08X into %08X at bits [1-4] => %08X\n", M, N,
		Problems::Insert(N, M, 1, 4));

	const int A = 29;
	const int B = 15;
	printf("Bit swap count from %08X to %08X => %d\n", A, B,
		Problems::BitSwapRequired(A, B));
}