#include "StdAfx.h"

#include "Tests/TestRunner.h"

int main()
{
	//RunTest(ETestCase::Fibonacci);
	
	RunTest(ETestCase::Array);

	RunTest(ETestCase::DynArray);

	getchar();

  return 0;
}

