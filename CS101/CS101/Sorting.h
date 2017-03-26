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


}