#include "StdAfx.h"
#include "TestProblemBacktracking.h"

#include "Problems/ProblemBacktracking.h"

CTestProblemBacktracking::CTestProblemBacktracking()
	: CBaseTest("Problems Backtracking")
{
}

void CTestProblemBacktracking::Run()
{
	printf("Eight Queens:\n");
	
	CS101::CLinkedList< CS101::CDynArray<int>> solutions;
	Problems::SolveEightQueens(solutions);
	
	int solCount = 0;
	for (auto pSolution = solutions.Begin(); pSolution != nullptr; pSolution = pSolution->pNext)
	{
		std::string line;
		line.reserve(128);
		
		line.append("\t[ ");
		for (size_t i = 0; i < pSolution->data.Size(); ++i)
		{
			line.append(std::to_string(pSolution->data[i]));
			if (i != pSolution->data.Size() - 1)
				line.append(", ");
		}
		line.append(" ]");
		
		printf("Solution %d - %s\n", ++solCount, line.c_str());
	}
}
