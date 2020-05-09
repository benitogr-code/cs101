#pragma once

#include <functional>
#include <memory>

template<typename T>
struct SAVLTreeNode
{
	SAVLTreeNode(const T& _data)
		: data(_data)
		, height(1)
	{

	}

	T   data;
	int height;

	std::shared_ptr<SAVLTreeNode> pLeft;
	std::shared_ptr<SAVLTreeNode> pRight;
};

/**
	AVL Tree
	A balanced binary tree

	Usage: AVLTree<int>, AVLTree<MyType>
*/
template<typename T>
class CAVLTree
{
private:
	typedef SAVLTreeNode<T>           NodeType;
	typedef std::shared_ptr<NodeType> NodeTypePtr;

public:
	~CAVLTree()
	{
		m_pRoot = Clear(m_pRoot);
	}

	int Height() const
	{
		return GetNodeHeight(m_pRoot);
	}

	bool Contains(const T& value) const
	{
		return Find(m_pRoot, value);
	}

	void Insert(const T& value)
	{
		m_pRoot = Insert(m_pRoot, value);
	}

	void Remove(const T& value)
	{
		m_pRoot = Remove(m_pRoot, value);
	}

	void VisitInOrder(const std::function<void(const T& value)>& visitor)
	{
		VisitInOrder(m_pRoot, visitor);
	}

private:

	int GetNodeHeight(const NodeTypePtr& pNode) const
	{
		return (pNode != nullptr) ? pNode->height : 0;
	}

	int GetNodeBalance(const NodeTypePtr& pNode) const
	{
		if (pNode != nullptr)
		{
			return (GetNodeHeight(pNode->pLeft) - GetNodeHeight(pNode->pRight));
		}
		else
		{
			return 0;
		}
	}

	NodeTypePtr FindSmallestKey(const NodeTypePtr& pNode) const
	{
		assert(pNode != nullptr);

		NodeTypePtr pResult = pNode;
		while (pResult->pLeft != nullptr)
			pResult = pResult->pLeft;

		return pResult;
	}

	NodeTypePtr AddNode(const T& value) const
	{
		return NodeTypePtr(new NodeType(value));
	}

	NodeTypePtr Insert(NodeTypePtr pNode, const T& value)
	{
		// Peform BST insertion
		if (pNode == nullptr)
			return AddNode(value);

		if (value < pNode->data)
			pNode->pLeft = Insert(pNode->pLeft, value);
		else if (pNode->data < value)
			pNode->pRight = Insert(pNode->pRight, value);
		else
			return pNode;

		// Adjust height
		pNode->height = 1 + std::max(GetNodeHeight(pNode->pLeft), GetNodeHeight(pNode->pRight));

		// Check if re-balance is needed
		const int balance = GetNodeBalance(pNode);

		// Left-Left
		if ((balance > 1) && (value < pNode->pLeft->data))
			return RotateRight(pNode);

		// Right-Right
		if ((balance < -1) && (pNode->pRight->data < value))
			return RotateLeft(pNode);

		// Left-Right
		if ((balance > 1) && (pNode->pLeft->data < value))
		{
			pNode->pLeft = RotateLeft(pNode->pLeft);
			return RotateRight(pNode);
		}

		// Right-Left
		if ((balance < -1) && (value < pNode->pRight->data))
		{
			pNode->pRight = RotateRight(pNode->pRight);
			return RotateLeft(pNode);
		}

		return pNode;
	}

	NodeTypePtr Remove(NodeTypePtr pNode, const T& value)
	{
		// BST removal
		if (pNode == nullptr)
			return pNode;

		if (value < pNode->data)
		{
			pNode->pLeft = Remove(pNode->pLeft, value);
		}
		else if (pNode->data < value)
		{
			pNode->pRight = Remove(pNode->pRight, value);
		}
		else
		{
			// Node has no child, just remove it
			if ((pNode->pLeft == nullptr) && (pNode->pRight == nullptr))
			{
				return nullptr;
			}
			else if (pNode->pLeft == nullptr)
			{
				pNode = pNode->pRight;
			}
			else if (pNode->pRight == nullptr)
			{
				pNode = pNode->pLeft;
			}
			else
			{
				NodeTypePtr pReplacement = FindSmallestKey(pNode);

				pNode->data = pReplacement->data;
				pNode->pRight = Remove(pNode->pRight, value);
			}
		}

		// Update height
		pNode->height = 1 + std::max(GetNodeHeight(pNode->pLeft), GetNodeHeight(pNode->pRight));

		// Re-balance if needed
		const int balance = GetNodeBalance(pNode);

		// Left-Left
		if ((balance > 1) && (GetNodeBalance(pNode->pLeft) >= 0))
			return RotateRight(pNode);

		// Right-Right
		if ((balance < -1) && (GetNodeBalance(pNode->pRight) <= 0))
			return RotateLeft(pNode);

		// Left-Right
		if ((balance > 1) && (GetNodeBalance(pNode->pLeft) < 0))
		{
			pNode->pLeft = RotateLeft(pNode->pLeft);
			return RotateRight(pNode);
		}

		// Right-Left
		if ((balance < -1) && (GetNodeBalance(pNode->pRight) > 0))
		{
			pNode->pRight = RotateRight(pNode->pRight);
			return RotateLeft(pNode);
		}

		return pNode;

	}

	NodeTypePtr Clear(NodeTypePtr pNode)
	{
		if (pNode != nullptr)
		{
			pNode->pLeft = Clear(pNode->pLeft);
			pNode->pRight = Clear(pNode->pRight);
		}

		return nullptr;
	}

	NodeTypePtr RotateLeft(NodeTypePtr pRoot)
	{
		NodeTypePtr pNewRoot = pRoot->pRight;
		NodeTypePtr pTemp = pNewRoot->pLeft;

		pNewRoot->pLeft = pRoot;
		pRoot->pRight = pTemp;

		pRoot->height = std::max(GetNodeHeight(pRoot->pLeft), GetNodeHeight(pRoot->pRight)) + 1;
		pNewRoot->height = std::max(GetNodeHeight(pNewRoot->pLeft), GetNodeHeight(pNewRoot->pRight)) + 1;

		return pNewRoot;
	}

	NodeTypePtr RotateRight(NodeTypePtr pRoot)
	{
		NodeTypePtr pNewRoot = pRoot->pLeft;
		NodeTypePtr pTemp = pNewRoot->pRight;

		pNewRoot->pRight = pRoot;
		pRoot->pLeft = pTemp;

		pRoot->height = std::max(GetNodeHeight(pRoot->pLeft), GetNodeHeight(pRoot->pRight)) + 1;
		pNewRoot->height = std::max(GetNodeHeight(pNewRoot->pLeft), GetNodeHeight(pNewRoot->pRight)) + 1;

		return pNewRoot;
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

	void VisitInOrder(NodeTypePtr pNode, const std::function<void(const T& value)>& visitor)
	{
		if (pNode != nullptr)
		{
			VisitInOrder(pNode->pLeft, visitor);
			visitor(pNode->data);
			VisitInOrder(pNode->pRight, visitor);
		}
	}

private:
	NodeTypePtr m_pRoot;
};
