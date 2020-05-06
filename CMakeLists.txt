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

set(main_sources
	src/pch.h
	src/pch.cpp
	src/main.cpp
)

add_executable(CS101
	${lib_sources}
	${problems_sources}
	${main_sources}
)

source_group(lib FILES ${lib_sources})
source_group(problems FILES ${problems_sources})
source_group(\\ FILES ${main_sources})

#install (TARGETS CS101 DESTINATION Bin)
