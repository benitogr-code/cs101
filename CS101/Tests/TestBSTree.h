#pragma once

#include "BaseTest.h"
#include "CS101/BSTree.h"

class CTestBSTree
	: public CBaseTest
{
public:
	CTestBSTree();

protected: 
	virtual void Run() override;

private:
	static void PrintTree(CS101::CBSTree<int>& tree);
};