#include "Graph.h"

//#define INF 999999

void Graph::addVertex(string name)
{
	Vertex* tmp = new Vertex;
	tmp->pi = name;
	tmp->dist = 0;
	vertices[name] = tmp;
}

void Graph::addEdge(string from, string to, int weight) 
{
	Neighbour tmp;
	tmp.name = to;
	tmp.weight = weight;
	adjList[from].push_back(tmp);
}

void Graph::buildSSPTree(string source)
{
	if(minQ.isEmpty())
	{
		cout << "The queue is empty" << endl;
	}
	else
	{
		cout << "The queue is NOT empty" << endl;
	}
	vertices[source]->dist = 0;
	for(auto v : vertices)
	{
		if(v.second->pi != source)
		{
		   v.second->dist = 999999;
			v.second->prev = NULL;
		}
		minQ.insert(v.second->pi, v.second->dist);
		cout << v.second->pi << endl;
	}
	minQ.print(); // 2 z's???
	while(!minQ.isEmpty())
	{
		cout << "." << endl;
		string u = minQ.extractmin();
		for(auto v : adjList[u])
		{
			int alt = vertices[u]->dist + v.weight;
			if(alt < vertices[v.name]->dist)
			{
				vertices[v.name]->dist = alt;
				vertices[v.name]->prev = vertices[u];
				minQ.decreasekeyM(v.name, alt);
			}
		}
	}
}

string Graph::getShortestPath(string from, string to)
{
	if(currentSource != from)
	{
		buildSSPTree(from);
		currentSource = from;
	}
	string result = "";
	for(Vertex* tmpVert = vertices[to]; tmpVert != NULL; tmpVert = tmpVert->prev)
	{
		result.insert(0, tmpVert->pi);
		if(tmpVert->pi != from)
		{
			result.insert(0, "->");
		}
	}
	result += " with length ";
	result += to_string(vertices[to]->dist);
	return result;
}



