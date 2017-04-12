#include "StdAfx.h"
#include "Utils.h"

#include <stdlib.h>

namespace CS101
{
	namespace Utils
	{
		void* AlignedMalloc(size_t size, size_t alignment)
		{
			const size_t extraSize = (alignment - 1) + sizeof(void*);
			void*  pAllocMemory = malloc(size + extraSize);
			if (pAllocMemory != nullptr)
			{
				void** pAlignedMemory = (void**)(((uintptr_t)pAllocMemory + extraSize) & ~(alignment - 1));
				pAlignedMemory[-1] = pAllocMemory;

				return pAlignedMemory;
			}

			return nullptr;
		}

		void AlignedFree(void* pMemory)
		{
			free(((void**)pMemory)[-1]);
		}
	}
}