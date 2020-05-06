#pragma once

#include "BaseTest.h"
#include "lib/Sorting.h"

class CTestSorting :
	public CBaseTest
{
public:
	CTestSorting();

protected:
	virtual void OnSetup() override;
	virtual void Run() override;

private:
	static void PrintValues(const char* szLabel, const CS101::CDynArray<int>& values);

private:
	CS101::CDynArray<int> m_values;
};
