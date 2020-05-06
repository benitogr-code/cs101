#pragma once

#include <assert.h>
#include <new>
#include <string.h>

/**
	Array with dynamic capacity
	Memory is dynamically allocated and resized as required.

	Usage: CDynArray<int>, CDynArray<MyType>, ...
*/
template<typename T>
class CDynArray
{
private:
	enum { DefaultSize = 4 };

public:
	typedef T* iterator;
	typedef const T* const_iterator;

public:
	CDynArray()
		: CDynArray(DefaultSize)
	{
	}

	explicit CDynArray(size_t capacity)
		: m_pData(nullptr)
		, m_capacity(DefaultSize)
		, m_size(0)
	{
		Grow(capacity);
	}

	CDynArray(const CDynArray<T>& rhs)
		: CDynArray(DefaultSize)
	{
		Copy(rhs);
	}

	~CDynArray()
	{
		Clear();

		delete[] m_pData;
		m_pData = nullptr;
	}

	size_t Capacity() const { return m_capacity; }
	size_t Size() const { return m_size; }
	bool   Empty() const { return (m_size == 0); }

	T& operator[](size_t index)
	{
		return At(index);
	}

	const T& operator[](size_t index) const
	{
		return At(index);
	}

	void operator=(const CDynArray<T>& rhs)
	{
		Copy(rhs);
	}

	T& Back()
	{
		assert(m_size > 0);
		return At(m_size - 1);
	}

	const T& Back() const
	{
		assert(m_size > 0);
		return At(m_size - 1);
	}

	iterator Begin()
	{
		return reinterpret_cast<T*>(m_pData);
	}

	const_iterator Begin() const
	{
		return reinterpret_cast<T*>(m_pData);
	}

	iterator End()
	{
		return Begin() + m_size;
	}

	const_iterator End() const
	{
		return Begin() + m_size;
	}

	void PushBack()
	{
		if ((m_size + 1) > m_capacity)
		{
			Grow(m_capacity * 2);
		}

		T* pNew = &(reinterpret_cast<T*>(m_pData)[m_size]);
		new(pNew) T();
		m_size++;
	}

	void PushBack(const T& value)
	{
		if ((m_size + 1) > m_capacity)
		{
			Grow(m_capacity * 2);
		}

		T* pNew = &(reinterpret_cast<T*>(m_pData)[m_size]);
		new(pNew) T(value);
		m_size++;
	}

	void PopBack()
	{
		if (m_size > 0)
		{
			Back().~T();
			m_size--;
		}
	}

	void Clear()
	{
		while (!Empty())
		{
			T& element = Back();
			element.~T();
			m_size--;
		}

		memset(m_pData, 0, sizeof(T) * m_capacity);
	}

private:
	void Grow(size_t capacity)
	{
		size_t newCapacity = m_capacity;
		while (newCapacity < capacity)
		{
			newCapacity *= 2;
		}

		char* pNewData = new char[sizeof(T) * newCapacity]();
		memcpy(pNewData, m_pData, sizeof(T) * m_size);

		delete[] m_pData;
		m_capacity = newCapacity;
		m_pData = pNewData;
	}

	T& At(size_t pos)
	{
		assert(pos < m_size);
		return reinterpret_cast<T*>(m_pData)[pos];
	}

	const T& At(size_t pos) const
	{
		assert(pos < m_size);
		return reinterpret_cast<T*>(m_pData)[pos];
	}

	void Copy(const CDynArray<T>& rhs)
	{
		if (Capacity() < rhs.Size())
			Grow(rhs.Size());

		memcpy(m_pData, rhs.Begin(), sizeof(T) * rhs.Size());
		m_size = rhs.Size();
	}

private:
	char* m_pData;
	size_t  m_capacity;
	size_t  m_size;
};
