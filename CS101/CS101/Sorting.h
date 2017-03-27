#pragma once

#include "DynArray.h"

namespace CS101
{
	template<typename T>
	void SortSelect(DynArray<T>& items)
	{
		for (size_t i = 0; i < (items.Size() - 1); ++i)
		{
			size_t minIdx = i;
			T minValue = items[i];
			for (size_t j = i + 1; j < items.Size(); ++j)
			{
				if (minValue < items[j])
					continue;

				minValue = items[j];
				minIdx = j;
			}

			T temp = items[minIdx];
			items[minIdx] = items[i];
			items[i] = temp;
		}
	}

	template<typename T>
	void SortBubble(DynArray<T>& items)
	{
		for (int i = 0; i < items.Size(); ++i)
		{
			for (int j = 0; j < (items.Size() - i - 1); ++j)
			{
				if (items[j] <= items[j + 1])
					continue;

				T temp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = temp;
			}
		}
	}

	template<typename T>
	void SortInsert(DynArray<T>& items)
	{
		for (int i = 1; i < items.Size(); ++i)
		{
			for (int j = i; (j > 0) && (items[j] < items[j - 1]); --j)
			{
				T temp = items[j];
				items[j] = items[j - 1];
				items[j - 1] = temp;
			}
		}
	}

}