#include "StdAfx.h"

#include "CS101/MathUtils.h"

void TestMaxCommonDivisor()
{
	for (unsigned int i = 27; i < 1000000; i *= 13)
	{
		printf("(%u, %u) - Basic %u, Euclides %u\n", 
			i, i/5,
			CS101::MaxCommonDivisor(i, i/5), CS101::MaxCommonDivisor(i, i/5));
	}
}

void TestFibonacci()
{
	for (unsigned int i = 0; i <= 20; ++i)
	{
		printf("Fibonacci(%u) = %u\n", i, CS101::Fibonacci(i));
	}
}

int main()
{
	TestFibonacci();

	getchar();

    return 0;
}

