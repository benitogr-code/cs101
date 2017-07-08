cmake_minimum_required (VERSION 3.1)

project (CS101)

set (CMAKE_CXX_STANDARD 11)

include_directories ("${PROJECT_SOURCE_DIR}/CS101")

set(cs101_sources
	CS101/CS101/Array.h
	CS101/CS101/AVLTree.h
	CS101/CS101/BigInt.h
	CS101/CS101/BigInt.cpp
	CS101/CS101/BSTree.h
	CS101/CS101/DynArray.h
	CS101/CS101/Graph.h
	CS101/CS101/HashMap.h
	CS101/CS101/LinkedList.h
	CS101/CS101/MathUtils.h
	CS101/CS101/MinHeap.h
	CS101/CS101/Queue.h
	CS101/CS101/Sorting.h
	CS101/CS101/Stack.h
	CS101/CS101/StringBuilder.h
	CS101/CS101/Utils.h
	CS101/CS101/Utils.cpp
)

set(problems_sources
	CS101/Problems/ProblemBacktracking.h
	CS101/Problems/ProblemBacktracking.cpp
	CS101/Problems/ProblemBits.h
	CS101/Problems/ProblemBits.cpp
	CS101/Problems/ProblemLinkedLists.h
	CS101/Problems/ProblemLinkedLists.cpp
	CS101/Problems/ProblemStacks.h
	CS101/Problems/ProblemStrings.h
	CS101/Problems/ProblemStrings.cpp
)

set(tests_sources
	CS101/Tests/BaseTest.h
	CS101/Tests/TestArray.h
	CS101/Tests/TestArray.cpp
	CS101/Tests/TestAVLTree.h
	CS101/Tests/TestAVLTree.cpp
	CS101/Tests/TestBigInt.h
	CS101/Tests/TestBigInt.cpp
	CS101/Tests/TestBSTree.h
	CS101/Tests/TestBSTree.cpp
	CS101/Tests/TestDynArray.h
	CS101/Tests/TestDynArray.cpp
	CS101/Tests/TestFibonacci.h
	CS101/Tests/TestFibonacci.cpp
	CS101/Tests/TestGraph.h
	CS101/Tests/TestGraph.cpp
	CS101/Tests/TestHashMap.h
	CS101/Tests/TestHashMap.cpp
	CS101/Tests/TestLinkedList.h
	CS101/Tests/TestLinkedList.cpp
	CS101/Tests/TestMinHeap.h
	CS101/Tests/TestMinHeap.cpp
	CS101/Tests/TestProblemBacktracking.h
	CS101/Tests/TestProblemBacktracking.cpp
	CS101/Tests/TestProblemBits.h
	CS101/Tests/TestProblemBits.cpp
	CS101/Tests/TestProblemLinkedLists.h
	CS101/Tests/TestProblemLinkedLists.cpp
	CS101/Tests/TestProblemStacks.h
	CS101/Tests/TestProblemStacks.cpp
	CS101/Tests/TestProblemStrings.h
	CS101/Tests/TestProblemStrings.cpp
	CS101/Tests/TestQueue.h
	CS101/Tests/TestQueue.cpp
	CS101/Tests/TestRunner.h
	CS101/Tests/TestRunner.cpp
	CS101/Tests/TestSorting.h
	CS101/Tests/TestSorting.cpp
	CS101/Tests/TestStack.h
	CS101/Tests/TestStack.cpp
	CS101/Tests/TestStringBuilder.h
	CS101/Tests/TestStringBuilder.cpp
	CS101/Tests/TestUtils.h
	CS101/Tests/TestUtils.cpp
)

set(main_sources
	CS101/StdAfx.h
	CS101/StdAfx.cpp
	CS101/Main.cpp
)

add_executable(CS101
	${cs101_sources}
	${problems_sources}
	${tests_sources}
	${main_sources}
)

source_group(CS101 FILES ${cs101_sources})
source_group(Problems FILES ${problems_sources})
source_group(Tests FILES ${tests_sources})
source_group(\\ FILES ${main_sources})

#install (TARGETS CS101 DESTINATION Bin)
