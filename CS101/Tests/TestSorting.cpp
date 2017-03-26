#include "StdAfx.h"
#include "TestSorting.h"

#include <random>

#define ARRAY_VALUES 37

CTestSorting::CTestSorting()
	: CBaseTest("Sorting algorithms")
	, m_values(ARRAY_VALUES)
{
}

void CTestSorting::OnSetup()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<> distribution(1, 128);

	for (int i = 0; i < ARRAY_VALUES; ++i)
	{
		m_values.PushBack(distribution(generator));
	}
}

void CTestSorting::Run()
{

	PrintValues("Initial values", m_values);

	// Selective sort
	{
		CS101::DynArray<int> tempValues = m_values;
		CS101::SortSelect(tempValues);

		PrintValues("Selective sort", tempValues);
	}
}

/*static*/ void CTestSorting::PrintValues(const char* szLabel, const CS101::DynArray<int>& values)
{
	printf("%s: \n\t", szLabel);
	for (int i = 0; i < values.Size(); ++i)
	{
		printf("%d, ", values[i]);
	}
	printf("\n");
}