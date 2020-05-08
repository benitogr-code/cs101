#include "catch.hpp"
#include "lib/Array.h"

#define TEST_CAPACITY 8

struct SCustomType {
	SCustomType(int _value) {
		value = _value;
		flag = true;
	}

	int  value;
	bool flag;
};

TEST_CASE( "Array operations", "[array]" ) {
	CArray<SCustomType, TEST_CAPACITY> array;

	REQUIRE(array.Capacity() == TEST_CAPACITY);
	REQUIRE(array.Size() == 0);

	SECTION( "should be full after filling it up" ) {
		for (int i = 0; i < array.Capacity(); ++i) {
			array.PushBack(SCustomType(i));
		}

		REQUIRE(array.IsFull() == true);
	}

	SECTION( "should contain push items" ) {
		array.PushBack(7);
		array.PushBack(25);
		array.PushBack(3);

		REQUIRE(array.Size() == 3);
		REQUIRE(array[1].value == 25);
	}

	SECTION( "should remove pop items" ) {
		for (int i = 0; i < array.Capacity(); ++i) {
			array.PushBack(SCustomType(i));
		}

		size_t lastSize = array.Size();

		array.PopBack();
		array.PopBack();

		REQUIRE(lastSize == (array.Size() + 2));
	}
}