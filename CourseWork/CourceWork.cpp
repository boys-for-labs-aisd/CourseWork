
#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

int main() 
{
	//srand(time(nullptr));
	int n = 2;
	Graph a = Graph(n);
	a.Output();
	Graph b = a;


	cout << "Expended" << endl;
	Graph exp = a.Expand(10);
	exp.Output();

	Graph test = exp.SearchIsomorphicSubgraph(a);

	test.Output();
	
	
	
	return 0;
}