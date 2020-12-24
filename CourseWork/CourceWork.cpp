
#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

int main() 
{
	srand(time(nullptr));
	int n = 2;
	Graph a = Graph(n);
	a.Output();
	Graph expendA = a.Expand(n + 2);
	cout << "Expended:" << endl;
	expendA.Output();
	
	return 0;
}