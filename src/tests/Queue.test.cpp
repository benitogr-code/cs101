#include "catch.hpp"
#include "lib/Queue.h"

#include <string>

TEST_CASE("Queue operations", "[queue]") {
	CQueue<std::string> queue;

	REQUIRE(queue.Empty() == true);

	SECTION("push and peek") {
		queue.Push(std::string("hello"));
		queue.Push(std::string("world"));
		queue.Push(std::string("!!"));

		REQUIRE(queue.Empty() == false);
		REQUIRE(queue.Peek().compare("hello") == 0);
	}

	SECTION("push and pop") {
		queue.Push(std::string("hello"));
		queue.Push(std::string("world"));
		queue.Push(std::string("!!"));

		auto top = queue.Pop();
		REQUIRE(top.compare("hello") == 0);

		queue.Pop();
		queue.Pop();

		REQUIRE(queue.Empty() == true);
	}

	SECTION("clear") {
		queue.Push(std::string("hello"));
		queue.Push(std::string("world"));
		queue.Push(std::string("!!"));

		queue.Clear();
		
		REQUIRE(queue.Empty() == true);
	}
}