#include "pch.h"
#include "TestProblemLinkedLists.h"

#include "Problems/ProblemLinkedLists.h"

CTestProblemLinkedLists::CTestProblemLinkedLists()
	: CBaseTest("Problems: Linked Lists")
{
}

void CTestProblemLinkedLists::Run()
{
	CS101::CLinkedList<int> list;
	for (int i = 0; i < 10; ++i)
	{
		list.Append(i + 1);
	}

	printf("List of is size %d\n", (int)list.Size());

	int value = 0;
	Problems::FindElementAtFromEnd(list, 4, value);
	printf("\t Element 4th from end is %d\n", value);

	Problems::FindElementAtFromEnd(list, 7, value);
	printf("\t Element 7th from end is %d\n", value);

	/////////////////////////////////////////////////

	CS101::CLinkedList<int> list1;
	list1.Append(2);
	list1.Append(2);
	list1.Append(3);

	CS101::CLinkedList<int> list2;
	list2.Append(7);
	list2.Append(8);

	printf("\n\n");

	printf("Sum of [2]-[2]-[3] + [7]-[8] = ");
	auto sumResult = Problems::SumLists(list1, list2);
	for (auto pNode = sumResult.Begin(); pNode != nullptr; pNode = pNode->pNext)
	{
		printf("[%d]%s", pNode->data, pNode != sumResult.End() ? "-" : "");
	}
}