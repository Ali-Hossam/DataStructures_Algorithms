#pragma once
#include "Node.h"
#include <vector>

class Graph
{
	std::map<std::string, Node*> graphMap;
	std::vector<std::string> nodes;
	int n = 0;	// number of nodes

public:
	void addNode(std::string name);
	void addEdge(std::string node1, std::string node2, int weight);
	Node* getNode(std::string name) const;
	int getNumberOfNodes() const;
	std::vector<std::string> getNodesVector() const{ return nodes; }
	~Graph();
};