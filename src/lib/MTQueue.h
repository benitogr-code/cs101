#pragma once

#include "Queue.h"

#include <mutex>
#include <condition_variable>

namespace CS101
{
	template<typename T>
	class CMTQueue
	{
	private:
		typedef std::unique_lock<std::mutex> TUniqueLock;
		
	public:
		~CMTQueue()
		{
			Clear();
		}
		
		void Push(const T& item)
		{
			TUniqueLock lockM(m_mutex);
			m_queue.Push(item);
			lockM.unlock();
			m_condVariable.notify_one();
		}
		
		T Pop()
		{
			TUniqueLock lockM(m_mutex);
			while(m_queue.Empty())
			{
				m_condVariable.wait(lockM);
			}
			T item = m_queue.Pop();
			return item;
		}
		
	private:
		void Clear()
		{
			TUniqueLock lockM(m_mutex);
			m_queue.Clear();
			lockM.unlock();
		}
		
	private:
		CQueue<T>   m_queue;
		
		std::mutex              m_mutex;
		std::condition_variable m_condVariable;
	};
}
