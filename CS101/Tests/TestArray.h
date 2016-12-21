#pragma once

#include "BaseTest.h"

#include "CS101/Array.h"

class CTestArray
	: public CBaseTest
{
public:
	CTestArray();

protected:
	virtual void OnSetup() override;
	virtual void Run() override;

private:
	CS101::Array<int, 32>   m_intArray;
	CS101::Array<float, 16> m_floatArray;
};
