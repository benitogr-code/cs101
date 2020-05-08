cmake_minimum_required (VERSION 3.1)

project (CS101)

set (CMAKE_CXX_STANDARD 11)

include_directories ("${PROJECT_SOURCE_DIR}/src")

set(lib_files
	src/lib/Algorithm.h
	src/lib/Array.h
	src/lib/AVLTree.h
	src/lib/BigInt.h
	src/lib/BigInt.cpp
	src/lib/BSTree.h
	src/lib/DynArray.h
	src/lib/HashMap.h
	src/lib/LinkedList.h
	src/lib/MinHeap.h
	src/lib/Queue.h
	src/lib/Stack.h
	src/lib/StringBuilder.h
)

set(test_files
	src/tests/catch.hpp
	src/tests/Array.test.cpp
	src/tests/DynArray.test.cpp
)

set(main_sources
	src/main.cpp
)

add_executable(CS101
	${lib_files}
	${test_files}
	${main_sources}
)

source_group(lib FILES ${lib_files})
source_group(tests FILES ${test_files})
source_group(\\ FILES ${main_sources})

#install (TARGETS CS101 DESTINATION Bin)
