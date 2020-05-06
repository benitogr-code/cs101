#pragma once

#include "lib/Stack.h"

namespace Problems
{
	// Description:
	// Sort the contents of stack using another stack
	template<typename T>
	void SortStack(CS101::CStack<T>& stack)
	{
		CS101::CStack<T> temp;
		while (!stack.Empty())
		{
			temp.Push(stack.Pop());
		}

		while (!temp.Empty())
		{
			T currentValue = temp.Pop();
			
			while (!stack.Empty() && (stack.Peek() > currentValue))
			{
				temp.Push(stack.Pop());
			}
			stack.Push(currentValue);
		}
	}
}
