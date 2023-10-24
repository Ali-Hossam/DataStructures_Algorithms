#include "graph.h"

void Graph::addNode(std::string name)
{
	graphMap[name] = new Node{ name };
	nodes.push_back(name);
	n++;

}

void Graph::addEdge(std::string node1, std::string node2, int weight)
{
	Node* from_node = getNode(node1);
	from_node->neighbors[node2] = weight;
	
	Node* neighbor = getNode(node2);
	neighbor->neighbors[node1] = weight;
}

Graph::~Graph()
{
	for (auto it = graphMap.begin(); it != graphMap.end(); it++)
	{
		delete it->second;
	}
}

Node* Graph::getNode(std::string name) const
{
	return graphMap.at(name);
}

int Graph::getNumberOfNodes() const { return n; }