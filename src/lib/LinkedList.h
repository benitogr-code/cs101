#pragma once

#include <assert.h>

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

/**
	LinkedList (Single linked list)
	Memory is allocated/ deallocated as individual nodes are inserted / removed.

	Usage: CLinkedList<TypeA>, CLinkedList<TypeB*>, ...
*/

template<typename T>
class CLinkedList
{
public:
	CLinkedList()
		: m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_size(0)
	{
	}

	CLinkedList(const CLinkedList<T>& rhs)
	{
		for (auto pNode = rhs.Begin(); pNode != nullptr; pNode = pNode->pNext)
		{
			Append(pNode->data);
		}
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

		m_size++;
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

		m_size++;
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

		m_size--;

		delete pNode;
	}

	size_t Size() const
	{
		return m_size;
	}

	const SListNode<T>* Begin() const
	{
		return m_pHead;
	}

	const SListNode<T>* End() const
	{
		return m_pTail;
	}

	const SListNode<T>* ItemAt(size_t index) {
		SListNode<T>* pNode = m_pHead;

		while ((pNode != nullptr) && (index > 0))
		{
			pNode = pNode->pNext;
			index--;
		}

		return pNode;
	}

private:
	SListNode<T>* m_pHead;
	SListNode<T>* m_pTail;
	size_t        m_size;
};

