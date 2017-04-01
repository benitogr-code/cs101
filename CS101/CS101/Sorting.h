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

	namespace Private
	{
		template<typename T>
		void Merge(DynArray<T>& items, size_t left, size_t middle, size_t right)
		{
			size_t helperSize = (right - left)+1;
			DynArray<T> helper(helperSize);

			for (size_t i = left; i <= right; ++i)
				helper.PushBack(items[i]);

			size_t helperMiddle = helper.Size() / 2;
			helperMiddle = (helperSize % 2 == 0) ? helperMiddle : helperMiddle + 1;

			size_t idxL = 0;
			size_t idxR = helperMiddle;
			size_t idxM = left;

			while ((idxL < helperMiddle) && (idxR < helperSize))
			{
				if (helper[idxL] <= helper[idxR])
				{
					items[idxM] = helper[idxL];
					++idxL;
				}
				else
				{
					items[idxM] = helper[idxR];
					++idxR;
				}
				++idxM;
			}

			while (idxL < helperMiddle)
			{
				items[idxM] = helper[idxL];
				++idxL;
				++idxM;
			}

			while (idxR < helperSize)
			{
				items[idxM] = helper[idxR];
				++idxR;
				++idxM;
			}
		}

		template<typename T>
		void SortMerge(DynArray<T>& items, size_t left, size_t right)
		{
			if (left < right)
			{
				size_t middle = (left + right) / 2;
				SortMerge(items, left, middle);
				SortMerge(items, middle + 1, right);
				Merge(items, left, middle, right);
			}
		}

		//////////

		template<typename T>
		int PerformPartition(DynArray<T>& items, int left, int right)
		{
			T pivot = items[(left + right) / 2];
			
			while (left <= right)
			{
				while (items[left] < pivot)
					++left;
				while (items[right] > pivot)
					--right;

				if (left <= right)
				{
					// Swap
					T temp = items[left];
					items[left] = items[right];
					items[right] = temp;

					++left;
					--right;
				}
			}

			return left;
		}

		template<typename T>
		void SortQuick(DynArray<T>& items, int left, int right)
		{
			int partIdx = PerformPartition(items, left, right);
			if (left < partIdx - 1)
			{
				SortQuick(items, left, partIdx - 1);
			}
			if (partIdx < right)
			{
				SortQuick(items, partIdx, right);
			}
		}
	}

	template<typename T>
	void SortMerge(DynArray<T>& items)
	{
		if (items.Size() > 1)
			Private::SortMerge(items, 0, items.Size()-1);
	}

	template<typename T>
	void SortQuick(DynArray<T>& items)
	{
		if (items.Size() > 1)
			Private::SortQuick(items, 0, (int)(items.Size() - 1));
	}

}