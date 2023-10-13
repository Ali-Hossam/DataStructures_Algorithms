#pragma once
#include "Node.h"

// a linked list used to store groceries with the same first letter
class List
{
private:
	Node* firstNode;
	Node* lastNode;

public:
	List(std::string name, float price);
	~List();
	bool remove(std::string name);	// removes an element from the list
	void add(std::string name, float price);	// adds an element to the list
	float getPrice(std::string name);
	Node* getFirstNode() const;
	Node* search(std::string key);	// search for node to remove, add or get it's price
};

