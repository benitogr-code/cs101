#include "catch.hpp"
#include "lib/Stack.h"

#include <string>

TEST_CASE("Stack operations", "[stack]") {
	CStack<std::string> stack;

	REQUIRE(stack.Empty() == true);

	SECTION("push and peek") {
		stack.Push(std::string("hello"));
		stack.Push(std::string("world"));
		stack.Push(std::string("!!"));

		REQUIRE(stack.Empty() == false);
		REQUIRE(stack.Peek().compare("!!") == 0);
	}

	SECTION("push and pop") {
		stack.Push(std::string("hello"));
		stack.Push(std::string("world"));
		stack.Push(std::string("!!"));

		auto top = stack.Pop();
		REQUIRE(top.compare("!!") == 0);

		stack.Pop();
		stack.Pop();

		REQUIRE(stack.Empty() == true);
	}
}