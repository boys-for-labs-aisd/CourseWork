#pragma once
#include <iostream>
#include <vector>


class Graph {
	friend class Vertex;
private:
	std::vector<Vertex*> Vertexs;
	int numVertexs;
public:
	

	Graph(int countVertex);
	void Output();
};

class Vertex{
private:
	int degree;
	
public:
	std::vector<int> AdjacentVert;

	Vertex();
	Vertex(int Degree);
};