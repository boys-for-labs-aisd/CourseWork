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
		//int startIndcol = rand() % (expandNumber - numVertexs + 1);
		int endIndrow = startIndrow + numVertexs - 1;
		//int endIndcol = startIndcol + numVertexs - 1;

		for (int i = startIndrow; i <= endIndrow; i++)
		{
			for (int j = startIndrow; j <= endIndrow; j++)
			{
				Vertex* vExpend = temp.Vertexs[i];
				Vertex* v = this->Vertexs[i - startIndrow];
				vExpend->AdjacentVert[j] = v->AdjacentVert[j - startIndrow];
			}

		}
	}
	return temp;
}

void Graph::SearchIsomorphicSubgraph(Graph subgraph)
{
	int rangeSearch = numVertexs - subgraph.NumVertexs();
	for (int i = 0; i < rangeSearch; i++)
	{

	}
}


bool Graph::isEqual(Graph subgraph)
{
	bool res = true;

	for (int i = 0; i < numVertexs && res; i++)
	{
		if (this->Vertexs[i] != subgraph.Vertexs[i])
		{
			res = false;
		}
	}

	return res;
}

Graph Graph::GetReplacedRowCol(int indexV1, int indexV2)
{
	Graph res = Graph(numVertexs, 'z');
	
	for (int i = 0; i < numVertexs; i++)
	{
		Vertex* vRes = res.Vertexs[i];
		Vertex* v = Vertexs[i];
		for (int j = 0; j < numVertexs; j++)
		{
			
			vRes->AdjacentVert[j] = v->AdjacentVert[j];

		}
	}
	
	std::swap(res.Vertexs[indexV1], res.Vertexs[indexV2]);

	for (int i = 0; i < numVertexs; i++)
	{
		Vertex* v = res.Vertexs[i];
		std::swap(v->AdjacentVert[indexV1], v->AdjacentVert[indexV2]);
	}
	return res;
}

