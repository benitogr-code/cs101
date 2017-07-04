#pragma once

namespace Problems
{
	// Description:
	// Given two strings, figure out if one is a permutation of the other
	bool IsPermutationOf(const std::string& str1, const std::string& str2);
	
	// Description:
	// Given two strings, figure out if they differ by one single edit
	bool IsOneEditAway(const std::string& str1, const std::string& str2);
}
