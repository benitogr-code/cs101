#pragma once

#include <memory>

template<typename T>
struct SBSTreeNode
{
	SBSTreeNode(const T& value)
		: data(value)
		, pLeft(nullptr)
		, pRight(nullptr)
	{
	}

	T data;

	std::shared_ptr<SBSTreeNode> pLeft;
	std::shared_ptr<SBSTreeNode> pRight;
};


/**
	Binary Search Tree
	Tree nodes are sorted, but not balanced. Custom types must provide comparison operators

	Usage: CBSTree<int>, CBSTree<MyType>
*/
template<typename T>
class CBSTree
{
private:
	typedef SBSTreeNode<T>   NodeType;
	typedef std::shared_ptr<NodeType> NodeTypePtr;

public:
	CBSTree()
		: m_pRoot(nullptr)
	{
	}

	~CBSTree()
	{
		m_pRoot = Clear(m_pRoot);
	}

	void Insert(const T& value)
	{
		m_pRoot = Insert(m_pRoot, value);
	}

	void Remove(const T& value)
	{
		m_pRoot = Remove(m_pRoot, value);
	}

	bool Contains(const T& value) const
	{
		return Find(m_pRoot, value);
	}

	size_t Height() const
	{
		return GetHeight(m_pRoot);
	}

	void VisitInOrder(const std::function<void(const T& value)>& visitor)
	{
		VisitInOrder(m_pRoot, visitor);
	}

	void VisitPreOrder(const std::function<void(const T& value)>& visitor)
	{
		VisitPreOrder(m_pRoot, visitor);
	}

	void VisitPostOrder(const std::function<void(const T& value)>& visitor)
	{
		VisitPostOrder(m_pRoot, visitor);
	}

protected:

	NodeTypePtr Insert(NodeTypePtr& pNode, const T& value)
	{
		if (pNode == nullptr)
		{
			return AddNode(value);
		}
		else
		{
			const T& nodeData = pNode->data;
			if (value < nodeData)
			{
				pNode->pLeft = Insert(pNode->pLeft, value);
				return pNode;
			}
			else if (nodeData < value)
			{
				pNode->pRight = Insert(pNode->pRight, value);
				return pNode;
			}
			else
			{
				return pNode;
			}
		}
	}

	NodeTypePtr Remove(NodeTypePtr& pNode, const T& value)
	{
		if (pNode != nullptr)
		{
			const T& nodeData = pNode->data;
			if (value < nodeData)
			{
				pNode->pLeft = Remove(pNode->pLeft, value);
			}
			else if (nodeData < value)
			{
				pNode->pRight = Remove(pNode->pRight, value);
			}
			else
			{
				// 1 - No children, just remove itself
				if ((pNode->pLeft == nullptr) && (pNode->pRight == nullptr))
					return nullptr;

				// 2 - One children, move it up
				if (pNode->pLeft == nullptr)
					return pNode->pRight;
				if (pNode->pRight == nullptr)
					return pNode->pLeft;

				// 3- Find smallest value on right side (or biggest on left side)
				NodeTypePtr pReplacement = RemoveSmallestOnRightBranch(pNode);
				pReplacement->pLeft = pNode->pLeft;
				pReplacement->pRight = pNode->pRight;

				return pReplacement;
			}

		}

		return pNode;
	}

	void VisitInOrder(const NodeTypePtr& pNode, const std::function<void(const T& value)>& visitor)
	{
		if (pNode == nullptr)
			return;

		VisitInOrder(pNode->pLeft, visitor);
		visitor(pNode->data);
		VisitInOrder(pNode->pRight, visitor);
	}

	void VisitPreOrder(const NodeTypePtr& pNode, const std::function<void(const T& value)>& visitor)
	{
		if (pNode == nullptr)
			return;

		visitor(pNode->data);
		VisitPreOrder(pNode->pLeft, visitor);
		VisitPreOrder(pNode->pRight, visitor);
	}

	void VisitPostOrder(const NodeTypePtr& pNode, const std::function<void(const T& value)>& visitor)
	{
		if (pNode == nullptr)
			return;

		VisitPostOrder(pNode->pLeft, visitor);
		VisitPostOrder(pNode->pRight, visitor);
		visitor(pNode->data);
	}

	NodeTypePtr AddNode(const T& value)
	{
		return NodeTypePtr(new NodeType(value));
	}

	NodeTypePtr Clear(NodeTypePtr& pNode)
	{
		if (pNode != nullptr)
		{
			pNode->pLeft = Clear(pNode->pLeft);
			pNode->pRight = Clear(pNode->pRight);
		}

		return nullptr;
	}

	size_t GetHeight(const NodeTypePtr& pRoot) const
	{
		if (pRoot == nullptr)
			return 0;

		return std::max<size_t>(GetHeight(pRoot->pLeft), GetHeight(pRoot->pRight)) + 1;
	}

	bool Find(const NodeTypePtr& pNode, const T& value) const
	{
		if (pNode == nullptr)
			return false;

		if (value < pNode->data)
			return Find(pNode->pLeft, value);
		else if (pNode->data < value)
			return Find(pNode->pRight, value);
		else
			return true;
	}

	NodeTypePtr RemoveSmallestOnRightBranch(NodeTypePtr& pNode)
	{
		NodeTypePtr pParent = pNode;
		NodeTypePtr pResult = pNode->pRight;

		bool bHasChildren = false;

		while (pResult->pLeft)
		{
			pParent = pResult;
			pResult = pResult->pLeft;
			bHasChildren = true;
		}

		if (bHasChildren)
			pParent->pLeft = nullptr;
		else
			pParent->pRight = nullptr;

		return pResult;
	}

private:
	NodeTypePtr m_pRoot;
};
