#pragma once

namespace CS101
{
	template<typename T>
	struct SBSTreeNode
	{
		SBSTreeNode(const T& value)
			: data(value)
			, pLeft(nullptr)
			, pRight(nullptr)
		{
		}

		T            data;
		SBSTreeNode* pLeft;
		SBSTreeNode* pRight;
	};

	template<typename T>
	class CBSTree
	{
	public:
		typedef typename SBSTreeNode<T> NodeType;

	private:
		typedef typename std::vector<NodeType*> Nodes;

	public:
		CBSTree()
			: m_pRoot(nullptr)
		{
		}

		~CBSTree()
		{
			for (auto pNode : m_nodes)
			{
				delete pNode;
			}

			m_nodes.clear();
			m_pRoot = nullptr;
		}

		void Insert(const T& value)
		{
			Insert(&m_pRoot, value);
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

		void Insert(NodeType** pRoot, const T& value)
		{
			if (*pRoot == nullptr)
			{
				*pRoot = AddNode(value);
			}
			else
			{
				const T& nodeData = (*pRoot)->data;
				if (nodeData == value)
					return;
				else if (nodeData > value)
					Insert(&(*pRoot)->pLeft, value);
				else
					Insert(&(*pRoot)->pRight, value);
			}
		}

		void VisitInOrder(const NodeType* pNode, const std::function<void(const T& value)>& visitor)
		{
			if (pNode == nullptr)
				return;

			VisitInOrder(pNode->pLeft, visitor);
			visitor(pNode->data);
			VisitInOrder(pNode->pRight, visitor);
		}

		void VisitPreOrder(const NodeType* pNode, const std::function<void(const T& value)>& visitor)
		{
			if (pNode == nullptr)
				return;

			visitor(pNode->data);
			VisitPreOrder(pNode->pLeft, visitor);
			VisitPreOrder(pNode->pRight, visitor);
		}

		void VisitPostOrder(const NodeType* pNode, const std::function<void(const T& value)>& visitor)
		{
			if (pNode == nullptr)
				return;

			VisitPostOrder(pNode->pLeft, visitor);
			VisitPostOrder(pNode->pRight, visitor);
			visitor(pNode->data);
		}

		NodeType* AddNode(const T& value)
		{
			m_nodes.push_back(new NodeType(value));
			return m_nodes.back();
		}

		size_t GetHeight(const NodeType* pRoot) const
		{
			if (pRoot == nullptr)
				return 0;

			return std::max<size_t>(GetHeight(pRoot->pLeft), GetHeight(pRoot->pRight)) + 1;
		}

		bool Find(NodeType* pNode, const T& value) const
		{
			if (pNode == nullptr)
				return false;

			if (pNode->data == value)
				return true;
			else if (pNode->data > value)
				return Find(pNode->pLeft, value);
			else
				return Find(pNode->pRight, value);
		}

	private:
		Nodes     m_nodes;
		NodeType* m_pRoot;
	};
}
