#include "StdAfx.h"
#include "TestBSTree.h"

#include "CS101/BSTree.h"

CTestBSTree::CTestBSTree()
	: CBaseTest("BSTree")
{
}

void CTestBSTree::Run()
{
	CS101::CBSTree<int> bsTree;
	
	std::vector<int> numbers = { 5, 7, 3, 1, 6, 8, 2, 4 };
	for (int value : numbers)
	{
		bsTree.Insert(value);
	}

	printf("BSTree height = %zu\n\n", bsTree.Height());

	printf("BSTree in order:");
	printf("\n\t");
	bsTree.VisitInOrder([](const int& value) 
		{
			printf("%d ", value);
		}
	);

	printf("\nBSTree pre order:");
	printf("\n\t");
	bsTree.VisitPreOrder([](const int& value)
		{
			printf("%d ", value);
		}
	);

	printf("\nBSTree post order:");
	printf("\n\t");
	bsTree.VisitPostOrder([](const int& value)
		{
			printf("%d ", value);
		}
	);
}