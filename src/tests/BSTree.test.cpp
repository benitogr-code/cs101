#include "catch.hpp"
#include "lib/BSTree.h"

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

TEST_CASE("BSTree operations", "[bstree]") {
	CBSTree<SData> tree;

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
}

TEST_CASE("BSTree visitor", "[bstree]") {
	CBSTree<SData> tree;

	tree.Insert(SData(10));
	tree.Insert(SData(1));
	tree.Insert(SData(20));
	tree.Insert(SData(30));

	CNodeVisitor<SData> visitor;
	std::function<void(const SData& value)> func = std::bind(&CNodeVisitor<SData>::Visit, &visitor, std::placeholders::_1);

	SECTION("in order") {
		tree.VisitInOrder(func);

		auto& nodes = visitor.GetData();

		REQUIRE(nodes[0].score == 1);
		REQUIRE(nodes[1].score == 10);
		REQUIRE(nodes[2].score == 20);
		REQUIRE(nodes[3].score == 30);
	}

	SECTION("pre order") {
		tree.VisitPreOrder(func);

		auto& nodes = visitor.GetData();

		REQUIRE(nodes[0].score == 10);
		REQUIRE(nodes[1].score == 1);
		REQUIRE(nodes[2].score == 20);
		REQUIRE(nodes[3].score == 30);
	}

	SECTION("post order") {
		tree.VisitPostOrder(func);

		auto& nodes = visitor.GetData();

		REQUIRE(nodes[0].score == 1);
		REQUIRE(nodes[1].score == 30);
		REQUIRE(nodes[2].score == 20);
		REQUIRE(nodes[3].score == 10);
	}
}