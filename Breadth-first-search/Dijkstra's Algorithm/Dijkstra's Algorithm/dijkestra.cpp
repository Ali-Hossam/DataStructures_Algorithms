#include "dijkestra.h"

void getShortestPath(std::string start, std::string end, Graph* network)
{
	// set the cost of the start node in the network to zero
	network->getNode(start)->cost = 0;

	// create a map with nodes and distances
	std::vector<std::string> nodes = network->getNodesVector();
	std::map<std::string, int> nonVisitednodes;
	std::map<std::string, int> Visitednodes;

	for (int i = 0; i < nodes.size(); i++)
	{
		// set non visited nodes weights as infinity
		if (nodes[i] == start) { nonVisitednodes[nodes[i]] = 0; }
		else nonVisitednodes[nodes[i]] = inf;
	}

	std::string currentNodeKey = start;

	int prevCost = 0;

	while (nonVisitednodes.size())
	{
		Node* currentNode = network->getNode(currentNodeKey);
		for (auto it = currentNode->neighbors.begin();
			it != currentNode->neighbors.end(); it++)
		{
			Node* neighbor = network->getNode(it->first);
			if (!neighbor->isVisited)
			{
				int edgeWeight = it->second;
				if (prevCost + edgeWeight < neighbor->cost)
				{
					neighbor->cost = prevCost + edgeWeight;
					neighbor->parent = currentNode;
					nonVisitednodes.at(it->first) = neighbor->cost;
				}
			}
		}
		// set current node as visited
		Visitednodes[currentNodeKey] = prevCost;
		currentNode->isVisited = true;

		// update non visited nodes
		nonVisitednodes.erase(currentNodeKey);

		// get nextNode
		if (nonVisitednodes.size())
		{
			currentNodeKey = getNextNode(nonVisitednodes);
			// update previous cost
			prevCost = nonVisitednodes.at(currentNodeKey);

		}

	}

	// get shortest path
	Node* currentNode = network->getNode(end);
	int sum = 0;
	while (currentNode != network->getNode(start))
	{
		currentNode = network->getNode(currentNodeKey);
		std::cout << currentNodeKey << ": " << currentNode->cost << "   ";
	
		sum += currentNode->cost;
		if(currentNode->key != start)
			currentNodeKey = currentNode->parent->key;
	}

	std::cout << "Total Cost: " << sum;

}

std::string getNextNode(std::map<std::string, int> nodesMap)
{
	int minValue = inf + 1;
	std::string minNode;

	for (auto it = nodesMap.begin(); it != nodesMap.end(); it++)
	{
		if (it->second < minValue)
		{
			minNode = it->first;
			minValue = it->second;
		}

	}
	return minNode;
}

