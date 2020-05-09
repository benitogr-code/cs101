#include "catch.hpp"
#include "lib/StringBuilder.h"

#include <string>

TEST_CASE("String builder", "[stringbuilder]") {
	CStringBuilder<32> builder;

	std::string line1 = "A list of city names:";
	std::string line2 = "\tValencia, Lisbon, Porto, Berlin, Oslo, Rome, etc.";
	const char* szLine3 = "======";

	builder
		.AppendLine(line1)
		.AppendLine(line2)
		.Append(szLine3);

	REQUIRE(builder.ToString() == (line1 + "\n" + line2 + "\n" + std::string(szLine3)));
}