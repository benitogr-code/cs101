#pragma once

namespace CS101
{
	namespace Utils
	{
		void* AlignedMalloc(size_t size, size_t alignment);
		void  AlignedFree(void* pMemory);
	}
}
