#pragma once
#include "World.h"


World::World(std::string myCountry) 
{ 
	this->myCountry = myCountry;
}

void World::addCountry(std::string country, std::string prevCountry)
{
	// create a new node for the country if no previous node exist with
	// this country name.
	Node* nodeToAdd;
	if (countryNode.find(country) != countryNode.end()) nodeToAdd = countryNode.at(country);
	else
	{
		nodeToAdd = new Node{ country };
		countryNode[country] = nodeToAdd;
	}
	
	// add the country to countriesRealtions map
	if (prevCountry == myCountry) bfsQueue.enqueue(nodeToAdd);
	
	std::vector<Node*> valuesToAdd = { nodeToAdd };
	if (countriesRelations.find(prevCountry) != countriesRelations.end())
	{
		countriesRelations[prevCountry].push_back(nodeToAdd);
	}
	else
		countriesRelations[prevCountry] = valuesToAdd;
}


int World::search(std::string destination)
{
	// c : number of nodes in the current lvl
	int c = countriesRelations[myCountry].size();
	int lvl = 1;
	queue doneQueue; // stores the dequeued nodes from bfsQueue
	
	while (!bfsQueue.isEmpty())
	{
		Node *nextCountry = bfsQueue.dequeue();
		doneQueue.enqueue(nextCountry);

		std::string nextCountryName = nextCountry->name;
		if (nextCountryName == destination)
		{
			return lvl;
		}
		else if(!(nextCountry->isSearched))
		{
			for (auto it = countriesRelations[nextCountryName].begin();
				it != countriesRelations[nextCountryName].end(); it++)
			{
				bfsQueue.enqueue(*it);
			}
			nextCountry->isSearched = true;
		}

		// update the level
		c--;
		if (!c)
		{
			lvl++;
			c = countriesRelations[doneQueue.dequeue()->name].size();
		}
	}
	return -1;

}