#pragma once

namespace CS101
{
	template<typename T, unsigned int CAPACITY>
	class Array
	{
		static_assert(CAPACITY > 0, "Array capacity must be greater than 0");

	public:
		Array()
			: m_size(0)
		{
		}

		inline unsigned int Capacity() const
		{
			return CAPACITY;
		}

		inline unsigned int Size() const
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
				m_values[m_size] = value;
				m_size++;
			}
		}

		inline void PopBack()
		{
			m_size -= (m_size > 0) ? 1 : 0;
		}

		inline T& operator[](unsigned int index)
		{
			assert(index < m_size);
			return m_values[index];
		}

		inline const T& operator[](unsigned int index) const
		{
			assert(index < m_size);
			return m_values[index];
		}

	private:
		T            m_values[CAPACITY];
		unsigned int m_size;
	};
}
