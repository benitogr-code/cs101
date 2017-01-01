#include "StdAfx.h"
#include "TestArray.h"

CTestArray::CTestArray()
	: CBaseTest("Array")
{
}

void CTestArray::OnSetup()
{
	int i = 0;
	while (!m_intArray.IsFull())
	{
		m_intArray.PushBack(i++);
	}

	float x = 3.141592f;
	while (m_floatArray.Size() < (m_floatArray.Capacity() / 2))
	{
		m_floatArray.PushBack(x);
		x *= 0.5f;
	}
}

void CTestArray::Run()
{
	printf("Array<int>: Size = %zu, Capacity = %zu\n", m_intArray.Size(), m_intArray.Capacity());
	printf("Values:\n");

	for (unsigned int i = 0; i < m_intArray.Size(); ++i)
	{
		printf("\t[%u] = %d\n", i, m_intArray[i]);
	}

	printf("\nArray<float>: Size = %zu, Capacity = %zu\n", m_floatArray.Size(), m_floatArray.Capacity());
	printf("Values:\n");

	for (unsigned int i = 0; i < m_floatArray.Size(); ++i)
	{
		printf("\t[%u] = %.6f\n", i, m_floatArray[i]);
	}
}