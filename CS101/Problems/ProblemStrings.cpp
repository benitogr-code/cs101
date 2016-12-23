#include "StdAfx.h"
#include "ProblemStrings.h"

namespace Problems
{
	bool IsPermutationOf(const std::string& str1, const std::string& str2)
	{
		if (str1.length() != str2.length())
			return false;

		int lookupTable[256];
		memset(lookupTable, 0, sizeof(int) * 256);

		for (size_t i = 0; i < str1.length(); ++i)
		{
			lookupTable[str1[i]]++;
		}

		for (size_t i = 0; i < str2.length(); ++i)
		{
			lookupTable[str2[i]]--;
			if (lookupTable[str2[i]] < 0)
				return false;
		}

		return true;
	}

	bool IsOneEditAway(const std::string& str1, const std::string& str2)
	{
		if (str1.length() == str2.length())
		{
			// Check single edit
			bool bEditFound = false;
			for (size_t i = 0; i < str1.length(); ++i)
			{
				if (str1[i] == str2[i])
					continue;

				if (bEditFound)
					return false;
				
				bEditFound = true;
			}

			return true;
		}
		else
		{
			// Check single insert (or remove)
			const std::string& sStr = str1.length() < str2.length() ? str1 : str2;
			const std::string& lStr = str1.length() > str2.length() ? str1 : str2;

			if (lStr.length() - sStr.length() > 1)
				return false;

			size_t sIndex = 0;
			size_t lIndex = 0;
			while ((sIndex < sStr.length()) && (lIndex < lStr.length()))
			{
				if (sStr[sIndex] == lStr[lIndex])
				{
					sIndex++;
					lIndex++;
				}
				else
				{
					lIndex++;
					if (lIndex - sIndex > 1)
						return false;
				}
			}

			return true;
		}
	}
}