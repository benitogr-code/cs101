#include <stdio.h>
#include <limits>

#include "lib/Array.h"
#include "lib/AVLTree.h"
#include "lib/BigInt.h"
#include "lib/BSTree.h"
#include "lib/DynArray.h"
#include "lib/HashMap.h"
#include "lib/LinkedList.h"
#include "lib/MinHeap.h"
#include "lib/Queue.h"
#include "lib/Sorting.h"
#include "lib/Stack.h"
#include "lib//StringBuilder.h"

int main()
{
	CArray<int, 8> array;
	CAVLTree<int> avlTree;
	CBigInt bigInt;
	CBSTree<int> bst;
	CDynArray<float> dynArray;
	CHashMap<int, int> hashMap;
	CLinkedList<float> linkedList;
	CMinHeap<int, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()> heap(32);
	CQueue<int> queue;
	CStack<int> stack;
	CStringBuilderDefault strBuilder;

	printf("Press any key to end the application.");
	getchar();

	return 0;
}

