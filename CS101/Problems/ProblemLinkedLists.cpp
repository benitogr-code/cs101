#include "StdAfx.h"
#include "ProblemLinkedLists.h"

namespace Problems
{
	CS101::CLinkedList<int> SumLists(const CS101::CLinkedList<int>& list1, const CS101::CLinkedList<int>& list2)
	{
		CS101::CLinkedList<int> listR;

		auto pOp1 = list1.Begin();
		auto pOp2 = list2.Begin();

		int carry = 0;
		while ((pOp1 != nullptr) || (pOp2 != nullptr))
		{
			const int value1 = (pOp1 != nullptr) ? pOp1->data : 0;
			const int value2 = (pOp2 != nullptr) ? pOp2->data : 0;
			const int sum = value1 + value2;

			listR.Append((sum + carry)%10);

			carry = (sum >= 10) ? 1 : 0;

			pOp1 = (pOp1 != nullptr) ? pOp1->pNext : nullptr;
			pOp2 = (pOp2 != nullptr) ? pOp2->pNext : nullptr;
		}

		return listR;
	}
}