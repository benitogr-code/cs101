#pragma once

#include "MathUtils.h"

#include <memory>

namespace CS101
{
	template<typename T>
	struct SAVLTreeNode
	{
		SAVLTreeNode(const T& _key)
			: key(_key)
			, height(1)
		{
		}

		T   key;
		int height;

		std::shared_ptr<SAVLTreeNode> pLeft;
		std::shared_ptr<SAVLTreeNode> pRight;
	};

	template<typename T>
	class CAVLTree
	{
	private:
		typedef typename SAVLTreeNode<T>           NodeType;
		typedef typename std::shared_ptr<NodeType> NodeTypePtr;

	public:

		int Height() const
		{
			return GetNodeHeight(m_pRoot);
		}

		void Insert(const T& key)
		{
			m_pRoot = Insert(m_pRoot, key);
		}

		void VisitPreOrder(const std::function<void(const T& key)>& visitor)
		{
			VisitPreOrder(m_pRoot, visitor);
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

		NodeTypePtr AddNode(const T& key) const
		{
			return NodeTypePtr(new NodeType(key));
		}

		NodeTypePtr Insert(NodeTypePtr pNode, const T& key)
		{
			// Peform BST insertion
			if (pNode == nullptr)
				return AddNode(key);

			if (key == pNode->key)
				return pNode;
			else if (key < pNode->key)
				pNode->pLeft = Insert(pNode->pLeft, key);
			else
				pNode->pRight = Insert(pNode->pRight, key);

			// Adjust height
			pNode->height = 1 + Maximum(GetNodeHeight(pNode->pLeft), GetNodeHeight(pNode->pRight));

			// Check if re-balance is needed
			const int balance = GetNodeBalance(pNode);

			// Left-Left
			if ((balance > 1) && (key < pNode->pLeft->key))
				return RotateRight(pNode);

			// Right-Right
			if ((balance < -1) && (key > pNode->pRight->key))
				return RotateLeft(pNode);

			// Left-Right
			if ((balance > 1) && (key > pNode->pLeft->key))
			{
				pNode->pLeft = RotateLeft(pNode->pLeft);
				return RotateRight(pNode);
			}

			// Right-Left
			if ((balance < -1) && (key < pNode->pRight->key))
			{
				pNode->pRight = RotateRight(pNode->pRight);
				return RotateLeft(pNode);
			}

			return pNode;
		}

		NodeTypePtr RotateLeft(NodeTypePtr pRoot)
		{
			NodeTypePtr pNewRoot = pRoot->pRight;
			NodeTypePtr pTemp = pNewRoot->pLeft;

			pNewRoot->pLeft = pRoot;
			pRoot->pRight = pTemp;

			pRoot->height = Maximum(GetNodeHeight(pRoot->pLeft), GetNodeHeight(pRoot->pRight)) + 1;
			pNewRoot->height = Maximum(GetNodeHeight(pNewRoot->pLeft), GetNodeHeight(pNewRoot->pRight)) + 1;

			return pNewRoot;
		}

		NodeTypePtr RotateRight(NodeTypePtr pRoot)
		{
			NodeTypePtr pNewRoot = pRoot->pLeft;
			NodeTypePtr pTemp = pNewRoot->pRight;

			pNewRoot->pRight = pRoot;
			pRoot->pLeft = pTemp;

			pRoot->height = Maximum(GetNodeHeight(pRoot->pLeft), GetNodeHeight(pRoot->pRight)) + 1;
			pNewRoot->height = Maximum(GetNodeHeight(pNewRoot->pLeft), GetNodeHeight(pNewRoot->pRight)) + 1;
		
			return pNewRoot;
		}

		void VisitPreOrder(NodeTypePtr pNode, const std::function<void(const T& key)>& visitor)
		{
			if (pNode != nullptr)
			{
				visitor(pNode->key);
				VisitPreOrder(pNode->pLeft, visitor);
				VisitPreOrder(pNode->pRight, visitor);
			}
		}

	private:
		NodeTypePtr m_pRoot;
	};
}