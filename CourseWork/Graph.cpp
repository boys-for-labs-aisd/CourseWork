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
Vertex::Vertex(int Degree, char zero)
{
	for (size_t i = 0; i < Degree; i++)
	{
		AdjacentVert.push_back(0);
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

Graph::Graph(int countVertex, char zero)
{
	for (size_t i = 0; i < countVertex; i++)
	{
		Vertexs.push_back(new Vertex(countVertex, 'z'));
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

Graph Graph::Expand(int expandNumber)
{
	Graph temp = Graph(expandNumber);
	if (expandNumber > numVertexs)
	{
		int startIndrow = rand() % (expandNumber - numVertexs + 1) ;
		int startIndcol = rand() % (expandNumber - numVertexs + 1);
		int endIndrow = startIndrow + numVertexs - 1;
		int endIndcol = startIndcol + numVertexs - 1;

		for (int i = startIndrow; i <= endIndrow; i++)
		{
			for (int j = startIndcol; j <= endIndcol; j++)
			{
				Vertex* vExpend = temp.Vertexs[i];
				Vertex* v = this->Vertexs[i - startIndrow];
				vExpend->AdjacentVert[j] = v->AdjacentVert[j - startIndcol];
			}

		}
	}
	return temp;
}

