#pragma once
#include <iostream>
#include <vector>


#include "Graph.h"

Vertex::Vertex(int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (rand() % 2)
		{
			AdjacentVert.push_back(1);
			degree++;
		}
		else
		{
			AdjacentVert.push_back(0);
		}
			
	}
	
}


Graph::Graph(int countVertex)
{
	for (size_t i = 0; i < countVertex; i++)
	{
		Vertexs.push_back(new Vertex(countVertex));
	}
	numVertexs = countVertex;
}

void Graph::Output()
{
	std::cout << "  ";
	for (size_t i = 0; i < numVertexs; i++)
	{
		std::cout << (char)('A' + i)<<' ';
	}
	std::cout << '\n';

	for (size_t i = 0; i < numVertexs; i++)
	{
		Vertex* v = Vertexs[i];
		std::cout << (char)('A' + i) << ' ';
		for (size_t j = 0; j < numVertexs; j++)
		{
			std::cout << v->AdjacentVert[j]<<' ';
		}
		std::cout << '\n';
	}

}