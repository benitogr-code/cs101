#include "StdAfx.h"
#include "TestAVLTree.h"

#include "CS101/AVLTree.h"

CTestAVLTree::CTestAVLTree()
	: CBaseTest("AVL Tree")
{
}

void CTestAVLTree::Run()
{
	CS101::CAVLTree<int> avlTree;

	avlTree.Insert(10);
	avlTree.Insert(20);
	avlTree.Insert(30);
	avlTree.Insert(40);
	avlTree.Insert(50);
	avlTree.Insert(25);

	printf("AVL (Pre-Order):\n");
	avlTree.VisitPreOrder([](const int& key)
		{
			printf("\t%d\n", key);
		}
	);
}