
#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

int main() 
{
	srand(time(nullptr));
	Graph a = Graph(rand()%10);
	a.Output();
	return 0;
}