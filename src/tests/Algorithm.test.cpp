#include "catch.hpp"
#include "lib/Algorithm.h"

bool IsArraySorted(const CDynArray<int>& array) {
	bool sorted = true;

	for (size_t i = 1; i < array.Size(); ++i) {
		sorted &= array[i - 1] <= array[i];
	}

	return sorted;
}

TEST_CASE("Sorting algorithms", "[sorting]") {
	CDynArray<int> items(32);

	for (size_t i = 0; i < items.Capacity(); ++i) {
		items.PushBack(rand());
	}

	SECTION("select sort") {
		Algorithm::SortSelect(items);

		REQUIRE(IsArraySorted(items) == true);
	}

	SECTION("bubble sort") {
		Algorithm::SortBubble(items);

		REQUIRE(IsArraySorted(items) == true);
	}

	SECTION("insert sort") {
		Algorithm::SortInsert(items);

		REQUIRE(IsArraySorted(items) == true);
	}

	SECTION("merge sort") {
		Algorithm::SortMerge(items);

		REQUIRE(IsArraySorted(items) == true);
	}

	SECTION("quick sort") {
		Algorithm::SortQuick(items);

		REQUIRE(IsArraySorted(items) == true);
	}

	SECTION("heap sort") {
		Algorithm::SortHeap(items);

		REQUIRE(IsArraySorted(items) == true);
	}
}