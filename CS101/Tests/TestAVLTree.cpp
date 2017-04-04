#include "StdAfx.h"
#include "TestAVLTree.h"

#include "CS101/AVLTree.h"

CTestAVLTree::CTestAVLTree()
	: CBaseTest("AVL Tree")
{
}

void CTestAVLTree::Run()
{
	// Test insert
	CS101::CAVLTree<int> avlTree;

	avlTree.Insert(9);
	avlTree.Insert(5);
	avlTree.Insert(10);
	avlTree.Insert(0);
	avlTree.Insert(6);
	avlTree.Insert(11);
	avlTree.Insert(-1);
	avlTree.Insert(1);
	avlTree.Insert(2);

	printf("AVL Tree (Pre-Order):\n");
	avlTree.VisitPreOrder([](const int& key)
		{
			printf("\t%d\n", key);
		}
	);

	// Test remove
	avlTree.Remove(10);

	printf("AVL after removing '10' (Pre-Order):\n");
	avlTree.VisitPreOrder([](const int& key)
		{
			printf("\t%d\n", key);
		}
	);
}