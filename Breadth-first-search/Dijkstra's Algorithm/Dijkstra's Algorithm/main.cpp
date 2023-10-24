#include "dijkestra.h"

int main()
{
	std::string nodes[] = { "a", "b", "c", "d", "e", "f", "g" };

	Graph network;
	for (int i = 0; i < (sizeof(nodes) / sizeof(std::string)); i++)
	{
		network.addNode(nodes[i]);
	}

	network.addEdge("a", "c", 1);
	network.addEdge("a", "d", 2);
	network.addEdge("b", "c", 2);
	network.addEdge("c", "d", 1);
	network.addEdge("b", "f", 3);
	network.addEdge("c", "e", 3);
	network.addEdge("e", "f", 2);
	network.addEdge("d", "g", 1);
	network.addEdge("g", "f", 1);

	getShortestPath("a", "f", &network);
	return 0;
}