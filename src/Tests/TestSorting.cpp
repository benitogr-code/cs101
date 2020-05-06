#include "pch.h"
#include "TestSorting.h"

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
	std::uniform_int_distribution<> distribution(1, 192);

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
		CS101::CDynArray<int> tempValues(m_values);
		CS101::SortSelect(tempValues);

		PrintValues("Selective sort", tempValues);
	}

	// Bubble sort
	{
		CS101::CDynArray<int> tempValues(m_values);
		CS101::SortBubble(tempValues);

		PrintValues("Bubble sort", tempValues);
	}

	// Insertion sort
	{
		CS101::CDynArray<int> tempValues(m_values);
		CS101::SortInsert(tempValues);

		PrintValues("Insertion sort", tempValues);
	}

	// Merge sort
	{
		CS101::CDynArray<int> tempValues(m_values);
		CS101::SortMerge(tempValues);

		PrintValues("Merge sort", tempValues);
	}

	// Quick sort
	{
		CS101::CDynArray<int> tempValues(m_values);
		CS101::SortQuick(tempValues);

		PrintValues("Quick sort", tempValues);
	}

	// Heap sort
	{
		CS101::CDynArray<int> tempValues(m_values);
		CS101::SortHeap(tempValues);

		PrintValues("Heap sort", tempValues);
	}
}

/*static*/ void CTestSorting::PrintValues(const char* szLabel, const CS101::CDynArray<int>& values)
{
	printf("%s: \n\t", szLabel);
	for (int i = 0; i < values.Size(); ++i)
	{
		printf("%d, ", values[i]);
	}
	printf("\n");
}
