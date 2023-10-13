#include "List.h"
List::List(std::string name, float price)
{
	firstNode = new Node{ name, price };
	lastNode = firstNode;
}

List::~List()
{
	delete firstNode;
}

Node* List::search(std::string key)
{
	Node *node = firstNode;
	while (node)
	{
		if (node->name == key) { return node; }
		else node = node->nextNode;
	}
	return nullptr;
}

bool List::remove(std::string name)
{
	Node* node = search(name);
	if (node)
	{
		if (firstNode == node)
		{
			firstNode = node->nextNode;
		}

		if (lastNode == node)
		{
			// if the node to be deleted is the last node
			// make the last node points to the parent of the current node
			lastNode = node->parentNode;
		}

		if(node->parentNode)
			node->parentNode->nextNode = node->nextNode;
		
		if(node->nextNode)
			node->nextNode->parentNode = node->parentNode;
	
		delete node;
		return true;
	}
	return false;
}

void List::add(std::string name, float price)
{
	// if the item exists, update the price otherwise add it
	Node* node = search(name);
	if (node)
	{
		node->price = price;
		return;
	}

	lastNode->nextNode = new Node{ name, price };
	lastNode->nextNode->parentNode = lastNode;
	lastNode = lastNode->nextNode;	
}

float List::getPrice(std::string name)
{
	Node* node = search(name);
	if (node) { return node->price; }
	else return -1;
}


Node* List::getFirstNode() const { return firstNode; }
