
//#ifndef _GRAPH_H_
//#define _GRAPH_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <assert.h>
#include "MinPriority.h"
using namespace std;
class Graph 
{

	private:
		class Vertex
			{
				public:
				string pi;
				int dist;
				Vertex* prev;
			};
		class Neighbour
			{
				public:
				string name;
				int weight;
			};
			string currentSource;
			map<string, Vertex*> vertices;
			map<string, vector<Neighbour> > adjList;
			MinPriority minQ;
			void buildSSPTree(string source);

	public:
			void addVertex(string name);
			void addEdge(string from, string to, int weight);
			string getShortestPath(string from,string to);
	
};


//#endif
