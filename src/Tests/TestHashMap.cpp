#include "pch.h"
#include "TestHashMap.h"

#include "lib/HashMap.h"

namespace Test
{

}

CTestHashMap::CTestHashMap()
	: CBaseTest("HashMap")
{
}

void CTestHashMap::Run()
{
	CS101::CHashMap<int, std::string> hashMap1;
	hashMap1.Insert(18, "Hello!");
	hashMap1.Insert(43254, "Benito is my name");
	hashMap1.Insert(3425, "What that...?!");
	hashMap1.Remove(3425);

	std::string value;
	hashMap1.TryGet(18, value);
	printf("HashMap[18] = %s\n", value.c_str());

	value.clear();
	hashMap1.TryGet(43254, value);
	printf("HashMap[43254] = %s\n", value.c_str());

	value.clear();
	hashMap1.TryGet(3425, value);
	printf("HashMap[3425] = %s\n\n", value.c_str());

	//////////////////////////////////////////////////////

	CS101::CHashMap<std::string, float, CS101::SStringHash> hashMap2;
	hashMap2.Insert("Benito", 5.0f);
	hashMap2.Insert("Ester", 4.5f);
	hashMap2.Insert("Dude", 2.0f);

	float fValue;
	hashMap2.TryGet("Benito", fValue);
	printf("Benito - %.2f\n", fValue);

	hashMap2.TryGet("Ester", fValue);
	printf("Ester - %.2f\n", fValue);

	hashMap2.TryGet("Dude", fValue);
	printf("Dude - %.2f\n", fValue);

	////////////////////////////////////////////////////
	CS101::CHashMap<int, int> hashMap3;
	for (int i = 0; i < 4096; ++i)
	{
		hashMap3.Insert(i, i);
	}
}