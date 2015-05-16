#include "Graph.h"

int main()
{
	Graph myGraph;
	myGraph.addVertex("s");
	myGraph.addVertex("t");
	myGraph.addVertex("x");
	myGraph.addVertex("y");	
	myGraph.addVertex("z");

	myGraph.addEdge("s","t",3);
	myGraph.addEdge("s","y",5);
	myGraph.addEdge("t","y",2);
	myGraph.addEdge("y","t",1);
	myGraph.addEdge("y","x",4);
	myGraph.addEdge("t","x",6);
	myGraph.addEdge("y","z",6);
	myGraph.addEdge("x","z",2);
	myGraph.addEdge("z","x",7);
	myGraph.addEdge("z","s",3);

	cout << myGraph.getShortestPath("s","x") << endl;
	cout << myGraph.getShortestPath("s","z") << endl;
	cout << myGraph.getShortestPath("t","z") << endl;

}
