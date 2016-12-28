#pragma once

namespace CS101
{
	template<typename T>
	struct SStackItem
	{
		SStackItem(const T& value)
			: data(value)
			, pNext(nullptr)
		{
		}

		T           data;
		SStackItem* pNext;
	};

	template<typename T>
	class CStack
	{
	public:
		CStack()
			: m_pTop(nullptr)
		{
		}

		~CStack()
		{
			while (!Empty())
			{
				Pop();
			}
		}

		bool Empty() const
		{
			return (m_pTop == nullptr);
		}

		void Push(const T& value)
		{
			auto pNewItem = new SStackItem<T>(value);

			if (m_pTop == nullptr)
			{
				m_pTop = pNewItem;
			}
			else
			{
				pNewItem->pNext = m_pTop;
				m_pTop = pNewItem;
			}
		}

		const T& Peek() const
		{
			assert(!Empty());

			return m_pTop->data;
		}

		T Pop()
		{
			assert(!Empty());

			T result = m_pTop->data;

			auto pNewTop = m_pTop->pNext;
			delete m_pTop;
			m_pTop = pNewTop;

			return result;
		}

	private:
		SStackItem<T>* m_pTop;
	};
}
