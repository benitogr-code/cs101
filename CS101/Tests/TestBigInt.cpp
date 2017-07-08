#include "StdAfx.h"
#include "TestBigInt.h"

#include "CS101/BigInt.h"


CTestBigInt::CTestBigInt()
	: CBaseTest("BigInt")
{
}

void CTestBigInt::Run()
{
	CS101::CBigInt a(2000000000000000LL);
	CS101::CBigInt b(7500000000000000LL);
	CS101::CBigInt c(a - b);
	CS101::CBigInt d(300000000000LL);
		
	printf("\t a = %s\n", a.ToString().c_str());
	printf("\t b = %s\n", b.ToString().c_str());
	printf("\t c = %s\n", c.ToString().c_str());
	printf("\t d = %s\n", d.ToString().c_str());
	printf("\t -d = %s\n", (-d).ToString().c_str());
	
	printf("\n");
	
	printf("\t a + b = %s\n", (a + b).ToString().c_str());
	printf("\t a - c = %s\n", (a - c).ToString().c_str());
	printf("\t c - c = %s\n", (c - c).ToString().c_str());
	printf("\t b * d = %s\n", (b * d).ToString().c_str());
	printf("\t a * c * a = %s\n", (a * c * a).ToString().c_str());
	printf("\t a < b is '%s'\n", a < b ? "true" : "false");
	printf("\t a > b is '%s'\n", a > b ? "true" : "false");
	printf("\t c >= c is '%s'\n", c >= c ? "true" : "false");
	printf("\t b == b is '%s'\n", b == b ? "true" : "false");
	printf("\t d != -d is '%s'\n", d != -d ? "true" : "false");
}
