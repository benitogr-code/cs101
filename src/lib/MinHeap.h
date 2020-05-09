#pragma once

#include "DynArray.h"

/**
	MinHeap (aka BinaryHeap or Priority Queue)
	Partially sorted data structure, implemented as a dynamic array.

	Usage: CMinHeap<uint, 0, 0xFFFFFFFF>, CMinHeap<float, FLOAT_MIN, FLOAT_MAX>, ...
*/
template<typename T, T MINVALUE, T MAXVALUE>
class CMinHeap
{
public:
	CMinHeap(size_t capacity)
		: m_heapArray(capacity)
		, m_capacity(capacity)
	{
	}

	bool Empty() const
	{
		return m_heapArray.Empty();
	}

	bool Full() const
	{
		return (m_heapArray.Size() == Capacity());
	}

	T GetMin() const
	{
		assert(!Empty());
		return m_heapArray[0];
	}

	T ExtractMin()
	{
		if (Empty())
			return MAXVALUE;

		const T value = m_heapArray[0];
		if (m_heapArray.Size() == 1)
		{
			m_heapArray.PopBack();
		}
		else
		{
			SwapKeys(0, m_heapArray.Size() - 1);
			m_heapArray.PopBack();
			HeapifyFrom(0);
		}

		return value;
	}

	void InsertKey(const T& key)
	{
		if (Full())
			return;

		// Put new key at the end of the heap
		m_heapArray.PushBack(key);

		// Fix structure if needed
		size_t idx = m_heapArray.Size() - 1;
		while ((idx != 0) && (KeyAt(Parent(idx)) > KeyAt(idx)))
		{
			SwapKeys(idx, Parent(idx));
			idx = Parent(idx);
		}
	}

protected:
	size_t Parent(size_t idx) const
	{
		return ((idx - 1) / 2);
	}

	size_t Left(size_t idx) const
	{
		return ((idx * 2) + 1);
	}

	size_t Right(size_t idx) const
	{
		return ((idx * 2) + 2);
	}

	const T& KeyAt(size_t idx) const
	{
		assert(idx < m_heapArray.Size());

		return m_heapArray[idx];
	}

	void DecreaseKey(size_t idx, const T& newKeyValue)
	{
		assert((idx < m_heapArray.Size()));

		m_heapArray[idx] = newKeyValue;
		while ((idx != 0) && (KeyAt(Parent(idx)) > KeyAt(idx)))
		{
			SwapKeys(idx, Parent(idx));
			idx = Parent(idx);
		}
	}

	size_t Capacity() const
	{
		return m_capacity;
	}

	void SwapKeys(size_t idx0, size_t idx1)
	{
		assert((idx0 < m_heapArray.Size()));
		assert((idx1 < m_heapArray.Size()));

		T temp = m_heapArray[idx0];
		m_heapArray[idx0] = m_heapArray[idx1];
		m_heapArray[idx1] = temp;
	}

	void HeapifyFrom(size_t idx)
	{
		size_t lIdx = Left(idx);
		size_t rIdx = Right(idx);
		size_t sIdx = idx;
		if ((lIdx < m_heapArray.Size()) && (KeyAt(lIdx) < KeyAt(sIdx)))
		{
			sIdx = lIdx;
		}
		if ((rIdx < m_heapArray.Size()) && (KeyAt(rIdx) < KeyAt(sIdx)))
		{
			sIdx = rIdx;
		}

		if (sIdx != idx)
		{
			SwapKeys(idx, sIdx);
			HeapifyFrom(sIdx);
		}
	}

private:
	CDynArray<T> m_heapArray;
	size_t       m_capacity;
};
