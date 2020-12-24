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
	void Output();
	Graph Expand(int expandNumber);
};

class Vertex{
private:
	int degree;
	
public:
	std::vector<int> AdjacentVert;

	Vertex(int Degree, char zero);
	Vertex(int Degree);
};