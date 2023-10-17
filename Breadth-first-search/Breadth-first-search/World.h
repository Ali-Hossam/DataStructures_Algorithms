#include "queue.h"
#include <map>


// class world stores my current contry, and other countires
// and it's search function uses BFS algorithm to return the 
// minimum lvl (depth of the tree) needed to get to the destination
// country.

class World
{
	std::string myCountry;
	std::map<std::string, std::vector<Node*>> countriesRelations;
	std::map<std::string, Node*> countryNode;	// map contry to node
	queue bfsQueue;

public:
	World(std::string myCountry);
	void addCountry(std::string country, std::string prevCountry);
	int search(std::string);
};