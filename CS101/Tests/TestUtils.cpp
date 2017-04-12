#include "StdAfx.h"

#include "TestUtils.h"
#include "CS101/Utils.h"

CTestUtils::CTestUtils()
	: CBaseTest("Utils")
{
}

void CTestUtils::Run()
{
	std::vector<void*> allocs;

	for (size_t alignement = 2; alignement <= 128; alignement *= 2)
	{
		void* pMemory = CS101::Utils::AlignedMalloc(1000, alignement);
		allocs.push_back(pMemory);

		printf("Aligned alloct (%d): %p\n", (int)alignement, pMemory);
	}

	while (!allocs.empty())
	{
		CS101::Utils::AlignedFree(allocs.back());
		allocs.pop_back();
	}
}