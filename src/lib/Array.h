#pragma once

/**
	Templated array with fixed capacity.
	Memory is statically allocated, not resizable.

	Usage: CArray<float, 8>, CArray<MyType, 32>, ...
*/
template<typename T, size_t CAPACITY>
class CArray
{
	static_assert(CAPACITY > 0, "Array capacity must be greater than 0");

public:
	CArray()
		: m_size(0)
	{
	}

	inline size_t Capacity() const
	{
		return CAPACITY;
	}

	inline size_t Size() const
	{
		return m_size;
	}

	inline bool IsFull() const
	{
		return (m_size >= CAPACITY);
	}

	inline void PushBack(const T& value)
	{
		if (!IsFull())
		{
			T* pNew = &(reinterpret_cast<T*>(m_values)[m_size]);
			new (pNew) T(value);
			m_size++;
		}
	}

	inline void PopBack()
	{
		if (m_size > 0)
		{
			T& element = At(m_size - 1);
			element.~T();
			m_size--;
		}
	}

	inline T& operator[](unsigned int index)
	{
		return At(index);
	}

	inline const T& operator[](unsigned int index) const
	{
		return At(index);
	}

private:
	T& At(size_t pos)
	{
		assert(pos < m_size);
		return (reinterpret_cast<T*>(m_values)[pos]);
	}

	const T& At(size_t pos) const
	{
		assert(pos < m_size);
		return (reinterpret_cast<T*>(m_values)[pos]);
	}

private:
	char   m_values[CAPACITY * sizeof(T)];
	size_t m_size;
};
