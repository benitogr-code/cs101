#pragma once

#include "BaseTest.h"

#include "lib/Array.h"

class CTestArray
	: public CBaseTest
{
public:
	CTestArray();

protected:
	virtual void OnSetup() override;
	virtual void Run() override;

private:
	CS101::CArray<int, 32>   m_intArray;
	CS101::CArray<float, 16> m_floatArray;
};
