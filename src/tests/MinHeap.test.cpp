#include "catch.hpp"
#include "lib/MinHeap.h"

#include <vector>
#include <limits>

TEST_CASE("MinHeap operations", "[minheap]") {
	CMinHeap<
		int, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()
	> heap(32);

	REQUIRE(heap.Empty() == true);
	REQUIRE(heap.Full() == false);

	std::vector<int> values = { 27, 237, 55, 897, 12, -47, 128, -99, 250, -3, 0 };

	for (int value : values) {
		heap.InsertKey(value);
	}

	REQUIRE(heap.GetMin() == -99);

	heap.ExtractMin();

	REQUIRE(heap.ExtractMin() == -47);
}