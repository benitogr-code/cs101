#include "StdAfx.h"
#include "TestBSTree.h"

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

	PrintTree(bsTree);

	printf("Removing value '5'...\n");
	bsTree.Remove(5);

	PrintTree(bsTree);
}

/*static*/ void CTestBSTree::PrintTree(CS101::CBSTree<int>& tree)
{
	printf("BSTree in order:");
	printf("\n\t");
	tree.VisitInOrder([](const int& value)
	{
		printf("%d ", value);
	}
	);

	printf("\n");
}