#include "catch.hpp"
#include "lib/DynArray.h"

TEST_CASE("DynArray capacity and resizing", "[dynarray]") {
	CDynArray<int> array;

	REQUIRE(array.Empty() == true);
	REQUIRE(array.Capacity() > array.Size());

	SECTION("should resize capacity on demand") {
		const size_t initialCapacity = array.Capacity();

		for (size_t i = 0; i < (initialCapacity + 2); ++i) {
			array.PushBack(rand());
		}

		REQUIRE(array.Capacity() > initialCapacity);
		REQUIRE(array.Size() == (initialCapacity + 2));
	}

	SECTION("should not resize after clear") {
		const size_t initialCapacity = array.Capacity();

		for (size_t i = 0; i < (initialCapacity + 2); ++i) {
			array.PushBack(rand());
		}

		array.Clear();

		REQUIRE(array.Empty() == true);
		REQUIRE(array.Capacity() > initialCapacity);
	}
}

bool AreEqual(const CDynArray<int>& a, const CDynArray<int>& b) {
	if (a.Size() != b.Size())
		return false;

	bool equal = true;
	for (size_t i = 0; i < a.Size(); ++i) {
		equal &= (a[i] == b[i]);
	}

	return equal;
}

TEST_CASE("DynArray copy", "[dynarray]") {
	CDynArray<int> array;

	for (size_t i = 0; i < 16; ++i) {
		array.PushBack(rand());
	}

	SECTION("with copy constructor") {
		CDynArray<int> copyArray(array);

		REQUIRE(AreEqual(array, copyArray) == true);
	}

	SECTION("with = operator") {
		CDynArray<int> copyArray(array);

		REQUIRE(AreEqual(array, copyArray));
	}
}

TEST_CASE("DynArray iterator", "[dynarray]") {
	CDynArray<int> array;

	for (int i = 0; i < 16; ++i) {
		array.PushBack(i);
	}

	int counter = 0;
	for (auto it = array.Begin(); it != array.End(); ++it) {
		counter++;
	}

	REQUIRE(counter == array.Size());
}