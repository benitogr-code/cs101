#include "StdAfx.h"
#include "TestQueue.h"

#include "CS101/Queue.h"

CTestQueue::CTestQueue()
	: CBaseTest("Queue")
{
}

void CTestQueue::Run()
{
	CS101::CQueue<int> queue;
	queue.Push(1);
	queue.Push(2);
	queue.Push(3);
	queue.Push(4);
	queue.Push(5);

	printf("Inpecting queue... (Peek front = '%d')\n\n", queue.Peek());
	while (!queue.Empty())
	{
		printf("\t%d\n", queue.Pop());
	}
}