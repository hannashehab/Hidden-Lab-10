#include <queue>
#include <vector>
#include <iostream>
#include "DirectedUnweightedGraph.h"
using namespace std;

DirectedUnweightedGraph::DirectedUnweightedGraph(int count)
{
	numberOfVertices = count;
	adjacencyList.resize(count);
}

void DirectedUnweightedGraph::addEdge(Edge edge)
{
	adjacencyList[edge.source].push_back(edge.destination);
}

void DirectedUnweightedGraph::BFS()
{
	vector <bool>visited(numberOfVertices, false);
	queue<int> queue;

	visited[0] = true;
	queue.push(0);

	while (!queue.empty())
	{
		int currentVertex = queue.front();
		cout << currentVertex << " ";
		queue.pop();

		for (int i = 0; i < adjacencyList[currentVertex].size(); i++)
		{
			int adjacentVertex = adjacencyList[currentVertex][i];
			if (!visited[adjacentVertex])
			{
				visited[adjacentVertex] = true;
				queue.push(adjacentVertex);
			}
		}
	}
}

void DirectedUnweightedGraph::DFS()
{
	vector<bool> visited(numberOfVertices, false);
	
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (!visited[i])
		{
			DFSRec(i, visited);
		}
	}
}

void DirectedUnweightedGraph::DFSRec(int vertex, vector<bool>& visited)
{
	visited[vertex] = true;
	cout << vertex << " ";

	for (int i = 0; i < adjacencyList[vertex].size(); i++)
	{
		int adjacentVertex = adjacencyList[vertex][i];
		if (!visited[adjacentVertex])
			DFSRec(adjacentVertex, visited);
	}
}
