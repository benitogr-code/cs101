#include "catch.hpp"
#include "lib/BigInt.h"

TEST_CASE("BigInt operations", "[bigint]") {
	CBigInt numberA(100000000);
	CBigInt numberB = numberA;
	CBigInt numberC = 200000000000;

	SECTION("equal") {
		REQUIRE(numberA == numberB);
		REQUIRE(numberA != numberC);
	}

	SECTION("less than") {
		REQUIRE(numberA < numberC);
		REQUIRE(numberA <= numberB);
	}

	SECTION("greater than") {
		REQUIRE(numberC > numberA);
		REQUIRE(numberA >= numberB);
	}

	SECTION("sum") {
		auto result = numberA + numberC + numberB;
		REQUIRE(result.ToString().compare("200200000000") == 0);

		result = numberA - numberB;
		REQUIRE(result.ToString().compare("0") == 0);
	}

	SECTION("substract") {
		auto result = -numberA;
		REQUIRE(result.ToString().compare("-100000000") == 0);

		result = numberB - result;
		REQUIRE(result.ToString().compare("200000000") == 0);
	}

	SECTION("multiplication") {
		auto result = -numberA * numberB * numberC;

		REQUIRE(result.ToString().compare("-2000000000000000000000000000") == 0);
	}
}