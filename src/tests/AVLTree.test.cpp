#include "catch.hpp"
#include "lib/AVLTree.h"

#include <vector>

struct SData {
	SData(int _score) {
		score = _score;
		flag = true;
	}

	bool operator<(const SData& rhs) const
	{
		return score < rhs.score;
	}

	int score;
	bool flag;
};


template<typename T>
class CNodeVisitor {
public:
	void Visit(const T& value) { m_data.push_back(value); }
	const std::vector<T>& GetData() const { return m_data; }

private:
	std::vector<T> m_data;
};

TEST_CASE("AVLTree operations", "[avltree]") {
	CAVLTree<SData> tree;

	REQUIRE(tree.Height() == 0);

	SECTION("insert and find") {
		tree.Insert(SData(25));
		tree.Insert(SData(4));
		tree.Insert(SData(32));

		REQUIRE(tree.Contains(SData(25)) == true);
		REQUIRE(tree.Contains(SData(64)) == false);

		REQUIRE(tree.Height() > 0);
	}

	SECTION("insert and remove") {
		tree.Insert(SData(25));
		tree.Insert(SData(4));
		tree.Insert(SData(32));

		REQUIRE(tree.Contains(SData(4)) == true);

		tree.Remove(SData(4));

		REQUIRE(tree.Contains(SData(4)) == false);
	}

	SECTION("height balance") {
		for (int i = 0; i < 107; ++i) {
			tree.Insert(SData(rand()));
		}

		REQUIRE(tree.Height() == 8);
	}

	SECTION("visit in order") {
		CNodeVisitor<SData> visitor;
		std::function<void(const SData& value)> func = std::bind(&CNodeVisitor<SData>::Visit, &visitor, std::placeholders::_1);

		for (int i = 0; i < 64; ++i) {
			tree.Insert(SData(i+1));
		}

		tree.VisitInOrder(func);

		auto& nodes = visitor.GetData();

		bool sorted = true;
		for (size_t i = 1; i < nodes.size(); ++i) {
			sorted &= nodes[i - 1] < nodes[i];
		}

		REQUIRE(nodes.size() == 64);
		REQUIRE(sorted == true);
	}
}