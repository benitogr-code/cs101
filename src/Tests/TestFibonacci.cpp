#include "pch.h"
#include "TestFibonacci.h"

CTestFibonacci::CTestFibonacci()
	: CBaseTest("Fibonacci")
{
}

void CTestFibonacci::Run()
{
	for (unsigned int i = 0; i <= 20; ++i)
	{
		printf("Fibonacci(%u) = %u\n", i, CS101::Fibonacci(i));
	}
}