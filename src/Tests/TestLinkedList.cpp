#include "pch.h"
#include "TestLinkedList.h"

#include "lib/LinkedList.h"

CTestLinkedList::CTestLinkedList()
	: CBaseTest("LinkedList")
{
}

void CTestLinkedList::Run()
{
	CS101::CLinkedList<int> list;

	list.Append(0);
	list.Append(1);
	list.Append(2);
	list.Append(3);
	list.Append(5);

	list.InsertAt(4, 4);
	list.InsertAt(7, 5);

	list.RemoveAt(5);

	int index = 0;
	for (auto pNode = list.Begin(); pNode != nullptr; pNode = pNode->pNext, index++)
	{
		printf("\tElement[%d] = %d\n", index, pNode->data);
	}
}