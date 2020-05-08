#include "catch.hpp"
#include "lib/LinkedList.h"

struct SCustomType {
	SCustomType(int _value) {
		value = _value;
		flag = true;
	}

	int  value;
	bool flag;
};

TEST_CASE("LinkedList basic operations", "[linkedlist]") {
	CLinkedList<SCustomType> list;

	REQUIRE(list.Size() == 0);
	REQUIRE(list.Begin() == list.End());

	SECTION("append items") {
		for (int i = 0; i < 8; ++i) {
			list.Append(SCustomType(i));
		}

		REQUIRE( list.Size() == 8 );
		REQUIRE(list.Begin()->data.value == 0);
		REQUIRE(list.End()->data.value == 7);
		REQUIRE(list.ItemAt(5)->data.value == 5);
	}

	SECTION("remove items") {
		for (int i = 0; i < 8; ++i) {
			list.Append(SCustomType(i));
		}

		list.RemoveAt(27); // Does nothing
		list.RemoveAt(5);

		REQUIRE(list.Size() == 7);
	}

	SECTION("insertAt position") {
		for (int i = 0; i < 4; ++i) {
			list.Append(SCustomType(i));
		}

		list.InsertAt(SCustomType(99), 2);

		REQUIRE(list.Size() == 5);
		REQUIRE(list.ItemAt(2)->data.value == 99);
		REQUIRE(list.ItemAt(3)->data.value == 2);
	}
}