#pragma once

#include <assert.h>

namespace CS101
{
	template<typename T>
	class DynArray
	{
	private:
		enum { DefaultSize = 4 };

	public:
		typedef T* iterator;
		typedef const T* const_iterator;

	public:
		DynArray()
			: DynArray(DefaultSize)
		{
		}

		explicit DynArray(size_t capacity)
			: m_pData(nullptr)
			, m_capacity(DefaultSize)
			, m_size(0)
		{
			Grow(capacity);
		}

		~DynArray()
		{
			Clear();

			delete[] m_pData;
			m_pData = nullptr;
		}

		// Capacity
		size_t Capacity() const { return m_capacity; }
		size_t Size() const { return m_size; }
		bool   Empty() const { return (m_size == 0); }

		// Element access
		T& operator[](size_t index)
		{
			assert(index < m_size);
			return m_pData[index];
		}

		const T& operator[](size_t index) const
		{
			assert(index < m_size);
			return m_pData[index];
		}

		T& Back()
		{
			assert(m_size > 0);
			return m_pData[m_size - 1];
		}

		const T& Back() const
		{
			assert(m_size > 0);
			return m_pData[m_size - 1];
		}

		iterator Begin()
		{
			return m_pData;
		}

		const_iterator Begin() const
		{
			return m_pData;
		}

		iterator End()
		{
			return !Empty() ? &m_pData[m_size-1] : m_pData;
		}

		const_iterator End() const
		{
			return !Empty() ? &m_pData[m_size-1] : m_pData;
		}

		// Modifiers
		void PushBack()
		{
			if ((m_size + 1) > m_capacity)
			{
				Grow(m_capacity * 2);
			}

			T* pNew = &m_pData[m_size];
			new(pNew) T();
			m_size++;
		}

		void PushBack(const T& value)
		{
			if ((m_size + 1) > m_capacity)
			{
				Grow(m_capacity * 2);
			}

			T* pNew = &m_pData[m_size];
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

			T* pNewData = reinterpret_cast<T*>(new char[sizeof(T)*newCapacity]());
			memcpy(pNewData, m_pData, sizeof(T) * m_size);

			delete[] m_pData;
			m_capacity = newCapacity;
			m_pData = pNewData;
		}

	private:
		T*      m_pData;
		size_t  m_capacity;
		size_t  m_size;
	};
}