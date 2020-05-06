cmake_minimum_required (VERSION 3.1)

project (CS101)

set (CMAKE_CXX_STANDARD 11)

include_directories ("${PROJECT_SOURCE_DIR}/src")

set(lib_sources
	src/lib/Array.h
	src/lib/AVLTree.h
	src/lib/BigInt.h
	src/lib/BigInt.cpp
	src/lib/BSTree.h
	src/lib/DynArray.h
	src/lib/HashMap.h
	src/lib/LinkedList.h
	src/lib/MathUtils.h
	src/lib/MinHeap.h
	src/lib/MTQueue.h
	src/lib/Queue.h
	src/lib/Sorting.h
	src/lib/Stack.h
	src/lib/StringBuilder.h
	src/lib/Utils.h
	src/lib/Utils.cpp
	src/lib/Trie.h
)

set(problems_sources
	src/Problems/ProblemBacktracking.h
	src/Problems/ProblemBacktracking.cpp
	src/Problems/ProblemBits.h
	src/Problems/ProblemBits.cpp
	src/Problems/ProblemLinkedLists.h
	src/Problems/ProblemLinkedLists.cpp
	src/Problems/ProblemStacks.h
	src/Problems/ProblemStrings.h
	src/Problems/ProblemStrings.cpp
)

set(tests_sources
	src/Tests/BaseTest.h
	src/Tests/TestArray.h
	src/Tests/TestArray.cpp
	src/Tests/TestAVLTree.h
	src/Tests/TestAVLTree.cpp
	src/Tests/TestBigInt.h
	src/Tests/TestBigInt.cpp
	src/Tests/TestBSTree.h
	src/Tests/TestBSTree.cpp
	src/Tests/TestDynArray.h
	src/Tests/TestDynArray.cpp
	src/Tests/TestFibonacci.h
	src/Tests/TestFibonacci.cpp
	src/Tests/TestHashMap.h
	src/Tests/TestHashMap.cpp
	src/Tests/TestLinkedList.h
	src/Tests/TestLinkedList.cpp
	src/Tests/TestMinHeap.h
	src/Tests/TestMinHeap.cpp
	src/Tests/TestMTQueue.h
	src/Tests/TestMTQueue.cpp
	src/Tests/TestProblemBacktracking.h
	src/Tests/TestProblemBacktracking.cpp
	src/Tests/TestProblemBits.h
	src/Tests/TestProblemBits.cpp
	src/Tests/TestProblemLinkedLists.h
	src/Tests/TestProblemLinkedLists.cpp
	src/Tests/TestProblemStacks.h
	src/Tests/TestProblemStacks.cpp
	src/Tests/TestProblemStrings.h
	src/Tests/TestProblemStrings.cpp
	src/Tests/TestQueue.h
	src/Tests/TestQueue.cpp
	src/Tests/TestRunner.h
	src/Tests/TestRunner.cpp
	src/Tests/TestSorting.h
	src/Tests/TestSorting.cpp
	src/Tests/TestStack.h
	src/Tests/TestStack.cpp
	src/Tests/TestStringBuilder.h
	src/Tests/TestStringBuilder.cpp
	src/Tests/TestUtils.h
	src/Tests/TestUtils.cpp
	src/Tests/TestTrie.h
	src/Tests/TestTrie.cpp
)

set(main_sources
	src/pch.h
	src/pch.cpp
	src/main.cpp
)

add_executable(CS101
	${lib_sources}
	${problems_sources}
	${tests_sources}
	${main_sources}
)

source_group(lib FILES ${lib_sources})
source_group(problems FILES ${problems_sources})
source_group(tests FILES ${tests_sources})
source_group(\\ FILES ${main_sources})

#install (TARGETS CS101 DESTINATION Bin)
