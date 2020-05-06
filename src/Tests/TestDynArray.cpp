#include "pch.h"
#include "TestDynArray.h"

#include "lib/DynArray.h"

namespace Test
{
	struct SSample
	{
		SSample()
			: intValue(0)
			, floatValue(27.5f)
		{}

		SSample(int _iValue, float _fValue)
			: intValue(_iValue)
			, floatValue(_fValue)
		{
		}

		int   intValue;
		float floatValue;
	};
}

CTestDynArray::CTestDynArray()
	: CBaseTest("DynArray")
{
}

void CTestDynArray::Run()
{
	CS101::CDynArray<int> dynArrayIntegers;

	for (int i = 0; i < 16; ++i)
	{
		dynArrayIntegers.PushBack(i*i);
	}

	printf("DynArray<int> - Capacity %zu - Size %zu\n", dynArrayIntegers.Capacity(), dynArrayIntegers.Size());
	for (int i = 0; i < dynArrayIntegers.Size(); ++i)
	{
		printf("\t Element[%u] = [%d]\n", i, dynArrayIntegers[i]);
	}

	///////////////////////////////////////////////////

	CS101::CDynArray<Test::SSample*> dynArraySample;

	for (int i = 0; i < 7; ++i)
	{
		dynArraySample.PushBack(new Test::SSample(i, i * 5.0f));
	}

	printf("DynArray<Test::SSample> - Capacity %zu - Size %zu\n", dynArraySample.Capacity(), dynArraySample.Size());
	for (auto iter = dynArraySample.Begin(); iter != dynArraySample.End(); ++iter)
	{
		printf("\t Element = [%d], [%.2f]\n", (*iter)->intValue, (*iter)->floatValue);
	
		delete (*iter);
	}

	dynArraySample.Clear();
}
