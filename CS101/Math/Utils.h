#pragma once

namespace Math
{
	template<typename T>
	inline int Minimum(T a, T b)
	{
		return (a <= b) ? a : b;
	}

	inline unsigned int MaxCommonDivisor(unsigned int a, unsigned int b)
	{
		unsigned int value = Minimum(a, b) + 1;
		do
		{
			value -= 1;
		} while (((a % value) != 0) || ((b % value) != 0));

		return value;
	}

	inline unsigned int MaxCommonDivisorEuclides(unsigned int a, unsigned int b)
	{
		while (a > 0)
		{
			unsigned int temp = a;
			a = b % a;
			b = temp;
		}

		return b;
	};

	inline unsigned int Fibonacci(unsigned int n)
	{
		unsigned int i = 1, j = 0;
		for (unsigned int k = 1; k <= n; ++k)
		{
			j = i + j;
			i = j - i;
		}

		return j;
	}
}
