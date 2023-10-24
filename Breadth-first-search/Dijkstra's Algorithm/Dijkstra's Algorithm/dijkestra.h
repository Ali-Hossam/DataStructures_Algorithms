#include <vector>
#include <iostream>
#include "graph.h"
void getShortestPath(std::string start, std::string end, Graph* network);
std::string getNextNode(std::map<std::string, int> nodesMap);

// the starting node has a cost of zero
// check neighbors of the starting node
// if prevCost + node cost < node cost -> update node cost
// store node with costs in a map
// update node parent
// choose the node with the lowest cost
// repeat
