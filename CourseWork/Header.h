#pragma once
#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
	int SumDegrees() {
		int sum = 0;
		for (int i = 0; i < Nodes.size(); ++i) {
			sum += Nodes[i].GetDegree();
		}
	}
	friend class Node;
private:
	std::vector<Node> Nodes;
	int NumberOfNodes;
};

class Node {
private:
	char Name;
	std::list<int> Pairs;
	int Degree;
public:
	char GetName() { return Name; }
	int GetDegree() { return Degree; }

};