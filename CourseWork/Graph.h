#pragma once
#include <iostream>
#include <vector>


class Graph {
	friend class Vertex;
private:
	std::vector<Vertex*> Vertexs;
	int numVertexs;
public:
	Graph(int countVertex, char zero);
	Graph(int countVertex);

	int NumVertexs() { return numVertexs; }
	void Output();
	Graph Expand(int expandNumber);

	void SearchIsomorphicSubgraph(Graph subgraph);
	bool isEqual(Graph subgraph);

	Graph GetReplacedRowCol(int indexV1, int indexV2);
};

class Vertex{
private:
	
public:
	std::vector<int> AdjacentVert;

	Vertex(int Degree, char zero);
	Vertex(int Degree);
};