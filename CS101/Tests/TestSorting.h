#pragma once

#include "BaseTest.h"
#include "CS101/Sorting.h"

class CTestSorting :
	public CBaseTest
{
public:
	CTestSorting();

protected:
	virtual void OnSetup() override;
	virtual void Run() override;

private:
	static void PrintValues(const char* szLabel, const CS101::DynArray<int>& values);

private:
	CS101::DynArray<int> m_values;
};
