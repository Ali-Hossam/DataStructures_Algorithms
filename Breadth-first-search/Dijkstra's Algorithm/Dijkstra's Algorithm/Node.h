#ifndef inf
#define inf 1000000
#include <map>
#include <string>


struct Node
{
	std::string key;
	int cost = inf;
	Node* parent = nullptr;
	bool isVisited = false;
	std::map<std::string, int> neighbors;	// neighbors[neighbor1, weight]
};

#endif