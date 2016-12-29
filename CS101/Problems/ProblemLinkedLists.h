#pragma once

#include "CS101/LinkedList.h"

namespace Problems
{
	template<typename T> 
	bool FindElementAtFromEnd(const CS101::CLinkedList<T>& list, size_t idx, T& outValue)
	{
		if (idx >= list.Size())
			return false;

		auto pNode1 = list.Begin();
		auto pNode2 = pNode1;
		while (idx > 0)
		{
			idx--;
			pNode2 = pNode2->pNext;
		}

		while (pNode2 != nullptr)
		{
			pNode1 = pNode1->pNext;
			pNode2 = pNode2->pNext;
		}

		outValue = pNode1->data;
		return true;
	}

	CS101::CLinkedList<int> SumLists(const CS101::CLinkedList<int>& list1, const CS101::CLinkedList<int>& list2);
}
