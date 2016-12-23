#pragma once

namespace CS101
{
	template<typename T>
	struct SListNode
	{
		SListNode(const T& value)
			: data(value)
			, pNext(nullptr)
		{
		}

		T          data;
		SListNode* pNext;
	};

	template<typename T>
	class CLinkedList
	{
	public:
		CLinkedList()
			: m_pHead(nullptr)
			, m_pTail(nullptr)
		{
		}

		~CLinkedList()
		{
			auto pNode = m_pHead;
			while (pNode != nullptr)
			{
				auto pTemp = pNode;
				pNode = pNode->pNext;
				delete pTemp;
			}

			m_pHead = m_pTail = nullptr;
		}

		void Append(const T& value)
		{
			if (m_pTail == nullptr)
			{
				assert(m_pHead == nullptr);

				m_pHead = new SListNode<T>(value);
				m_pTail = m_pHead;
			}
			else
			{
				assert(m_pTail->pNext == nullptr);

				auto pNewNode = new SListNode<T>(value);
				m_pTail->pNext = pNewNode;
				m_pTail = pNewNode;
			}
		}

		void InsertAt(const T& value, size_t index)
		{
			SListNode<T>* pNode = m_pHead;
			SListNode<T>* pPrev = nullptr;
			
			while ((pNode != nullptr) && (index > 0))
			{
				pPrev = pNode;
				pNode = pNode->pNext;
				index--;
			}

			if (pNode == nullptr)
				return;

			auto pNewNode = new SListNode<T>(value);
			if (pPrev != nullptr)
			{
				pNewNode->pNext = pNode;
				pPrev->pNext = pNewNode;
			}
			else
			{
				assert(pNode == m_pHead);
				pNewNode->pNext = pNode;
				m_pHead = pNewNode;
			}
		}

		void RemoveAt(size_t index)
		{
			SListNode<T>* pNode = m_pHead;
			SListNode<T>* pPrev = nullptr;

			while ((pNode != nullptr) && (index > 0))
			{
				pPrev = pNode;
				pNode = pNode->pNext;
				index--;
			}

			if (pNode == nullptr)
				return;

			if (pPrev != nullptr)
			{
				pPrev->pNext = pNode->pNext;
				if (pPrev->pNext == nullptr)
					m_pTail = pPrev;
			}
			else
			{
				m_pHead = pNode->pNext;
				if (m_pHead == nullptr)
					m_pTail = nullptr;
			}

			delete pNode;
		}

		const SListNode<T>* Begin() const
		{
			return m_pHead;
		}

		const SListNode<T>* End() const
		{
			return m_pTail;
		}

	private:
		SListNode<T>* m_pHead;
		SListNode<T>* m_pTail;
	};
}
