#pragma once
#include "node.h"
#include <iostream>
#include <map>
class Tree
{
private:
	struct Node* root;
	bool isEmpty;
	void clearNode(Node*);


public:
	Tree(Node&);
	~Tree();
	struct Node* search(int, Node*);
	struct Node insert(int, Node*);
	struct Node* remove(int, Node*);
	struct Node getRootNode() const;
	Node* inOrderSuccessor(int, Node*, int, int);
	
};

