#include "pch.h"
#include "TestProblemStrings.h"

#include "Problems/ProblemStrings.h"

CTestProblemStrings::CTestProblemStrings()
	: CBaseTest("Problems: Strings")
{
}

void CTestProblemStrings::Run()
{
	std::string str1 = "hello world";
	std::string str2 = "world helol";
	std::string str3 = "wolda heiyl";
	
	printf("'%s' is permutation of '%s' - %d\n", str1.c_str(), str2.c_str(), Problems::IsPermutationOf(str1, str2));
	printf("'%s' is permutation of '%s' - %d\n", str1.c_str(), str3.c_str(), Problems::IsPermutationOf(str1, str3));
	printf("'%s' is permutation of '%s' - %d\n", str2.c_str(), str3.c_str(), Problems::IsPermutationOf(str2, str3));

	printf("\n\n");

	printf("'pale' is one edit away of 'ple' - %d\n", Problems::IsOneEditAway("pale", "ple"));
	printf("'pales' is one edit away of 'pale' - %d\n", Problems::IsOneEditAway("pales", "pale"));
	printf("'pale' is one edit away of 'bale' - %d\n", Problems::IsOneEditAway("pale", "bale"));
	printf("'pale' is one edit away of 'bae' - %d\n", Problems::IsOneEditAway("pale", "bae"));
	printf("'pale' is one edit away of 'apales' - %d\n", Problems::IsOneEditAway("pale", "apales"));
}