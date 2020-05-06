#pragma once

#include "lib/LinkedList.h"

namespace Problems
{
	// Description:
	// Given a single linked list retrieve the element at a certain position from the end
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

	// Description:
	// Given two lists with nodes containing integer values between 0-9,
	// return the sum of both as another linked list
	CS101::CLinkedList<int> SumLists(const CS101::CLinkedList<int>& list1, const CS101::CLinkedList<int>& list2);
}
