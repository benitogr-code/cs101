#pragma once


template<typename T>
struct SQueueItem
{
	SQueueItem(const T& value)
		: data(value)
		, pNext(nullptr)
	{
	}

	T           data;
	SQueueItem* pNext;
};

/**
	Queue
	Implemented as a linked list with a front / back pointers.
	Memory is allocated/ deallocated as data is push/ pop from it.

	Usage: CQueue<int>, CQueue<MyType>, ...
*/
template<typename T>
class CQueue
{
public:
	CQueue()
		: m_pFront(nullptr)
		, m_pBack(nullptr)
	{
	}

	~CQueue()
	{
		Clear();
	}

	bool Empty() const
	{
		return (m_pFront == nullptr);
	}

	void Clear()
	{
		while (!Empty())
		{
			Pop();
		}
	}

	void Push(const T& value)
	{
		auto pNewItem = new SQueueItem<T>(value);

		if (m_pFront == nullptr)
		{
			assert(m_pBack == nullptr);

			m_pFront = pNewItem;
			m_pBack = pNewItem;
		}
		else
		{
			m_pBack->pNext = pNewItem;
			m_pBack = pNewItem;
		}
	}

	const T& Peek() const
	{
		assert(!Empty());

		return m_pFront->data;
	}

	T Pop()
	{
		assert(!Empty());

		T result = m_pFront->data;

		auto pNewFront = m_pFront->pNext;
		delete m_pFront;
		m_pFront = pNewFront;

		if (m_pFront == nullptr)
			m_pBack = nullptr;

		return result;
	}

private:
	CQueue(const CQueue& rhs);
	CQueue& operator=(const CQueue& rhs);

private:
	SQueueItem<T>* m_pFront;
	SQueueItem<T>* m_pBack;
};

