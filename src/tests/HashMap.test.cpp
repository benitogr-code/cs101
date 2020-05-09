#include "catch.hpp"
#include "lib/HashMap.h"

#include <string>

struct SStringHash
{
	unsigned long operator()(const std::string& key) const
	{
		unsigned long hash = 1024 * 32;
		for (int i = 0; i < key.length(); i += 3)
		{
			hash += key.at(i);
		}

		return hash;
	}
};

TEST_CASE("Hashmap operations", "[hashmap]") {
	CHashMap<int, std::string> map;

	SECTION("insert and find items") {
		map.Insert(100, std::string("Berlin"));
		map.Insert(200, std::string("Viena"));
		map.Insert(300, std::string("Madrid"));
		map.Insert(1000, std::string("Paris"));

		std::string city;
		map.TryGet(200, city);

		REQUIRE(city.compare("Viena") == 0);
	}

	SECTION("insert and remove") {
		map.Insert(64, std::string("Berlin"));
		map.Insert(512, std::string("Viena"));
		map.Insert(1024, std::string("Madrid"));
		map.Insert(128, std::string("Paris"));

		map.Remove(512);

		std::string city;
		map.TryGet(512, city);

		REQUIRE(city.empty());
	}
}

TEST_CASE("Hashmap custom hash function", "[hashmap]") {
	CHashMap<std::string, int, SStringHash> map;

	map.Insert(std::string("Berlin"), 32);
	map.Insert(std::string("Barcelona"), 256);
	map.Insert(std::string("Lisbon"), 355);

	int id = -1;
	map.TryGet(std::string("Lisbon"), id);

	REQUIRE(id == 355);

	id = -1;
	map.TryGet(std::string("Rome"), id);

	REQUIRE(id == -1);
}