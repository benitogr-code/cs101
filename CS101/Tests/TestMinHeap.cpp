#include "StdAfx.h"
#include "TestMinHeap.h"

#include "CS101/MinHeap.h"

CTestMinHeap::CTestMinHeap()
	: CBaseTest("MinHeap")
{
}

void CTestMinHeap::Run()
{
	CS101::CMinHeap<int, INT_MIN, INT_MAX> heap(16);
	heap.InsertKey(3);
	heap.InsertKey(2);
	heap.RemoveNode(1); 
	heap.InsertKey(15);
	heap.InsertKey(5);
	heap.InsertKey(4);
	heap.InsertKey(45);
	
	printf("Min (extract) %d\n", heap.ExtractMin());
	printf("Min (peek):   %d\n", heap.GetMin());
}