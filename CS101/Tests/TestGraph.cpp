#include "StdAfx.h"
#include "TestGraph.h"

#include "CS101/Graph.h"

CTestGraph::CTestGraph()
	: CBaseTest("Graph")
{

}

void CTestGraph::Run()
{
	CS101::CGraph<std::string> graph;
	graph.AddNode("A");
	graph.AddNode("B");
	graph.AddNode("C");
	graph.AddNode("D");
	graph.AddNode("E");
	graph.AddNode("F");
	graph.AddNode("G");

	graph.Connect("A", "B");
	graph.Connect("A", "C");
	graph.Connect("A", "D");
	graph.Connect("C", "E");
	graph.Connect("D", "E");
	graph.Connect("E", "F");
	graph.Connect("E", "G");

	printf("Visit DFS:\n");
	graph.VisitDFS([](const std::string& value)
		{
			printf("\t%s\n", value.c_str());
		});

	printf("Visit BFS:\n");
	graph.VisitBFS([](const std::string& value)
	{
		printf("\t%s\n", value.c_str());
	});

}