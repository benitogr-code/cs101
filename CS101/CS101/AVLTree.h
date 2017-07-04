#pragma once

#include "MathUtils.h"

#include <memory>

#define DEBUG_AVL_TREE 0

namespace CS101
{
#if DEBUG_AVL_TREE
	static int g_AVLTreeNodeCounter = 0;
#endif

	template<typename T>
	struct SAVLTreeNode
	{
		SAVLTreeNode(const T& _key)
			: key(_key)
			, height(1)
		{
#if DEBUG_AVL_TREE
			printf("\nAVLTreeNode (C-> %d).", ++g_AVLTreeNodeCounter);
#endif
		}

#if DEBUG_AVL_TREE
		~SAVLTreeNode()
		{
			printf("\nAVLTreeNode (D->%d).", --g_AVLTreeNodeCounter);
		}
#endif

		T   key;
		int height;

		std::shared_ptr<SAVLTreeNode> pLeft;
		std::shared_ptr<SAVLTreeNode> pRight;
	};

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

		void Insert(const T& key)
		{
			m_pRoot = Insert(m_pRoot, key);
		}

		void Remove(const T& key)
		{
			m_pRoot = Remove(m_pRoot, key);
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

		NodeTypePtr FindSmallestKey(const NodeTypePtr& pNode) const
		{
			assert(pNode != nullptr);

			NodeTypePtr pResult = pNode;
			while (pResult->pLeft != nullptr)
				pResult = pResult->pLeft;

			return pResult;
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

		NodeTypePtr Remove(NodeTypePtr pNode, const T& key)
		{
			// BST removal
			if (pNode == nullptr)
				return pNode;

			if (key < pNode->key)
			{
				pNode->pLeft = Remove(pNode->pLeft, key);
			}
			else if (key > pNode->key)
			{
				pNode->pRight = Remove(pNode->pRight, key);
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
					
					pNode->key = pReplacement->key;
					pNode->pRight = Remove(pNode->pRight, key);
				}
			}

			// Update height
			pNode->height = 1 + Maximum(GetNodeHeight(pNode->pLeft), GetNodeHeight(pNode->pRight));

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
