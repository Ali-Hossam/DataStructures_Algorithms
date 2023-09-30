#include "Tree.h"
#include <iostream>

void printTree(Node root);
int main()
{
	Node rootNode;
	Tree BST(rootNode);

	// Test insert
	BST.insert(2, &rootNode);
	BST.insert(3, &rootNode);
	BST.insert(4, &rootNode);
	BST.insert(1, &rootNode);
	BST.insert(0, &rootNode);
	BST.insert(-4, &rootNode);
	BST.insert(54, &rootNode);
	BST.insert(15, &rootNode);
	BST.insert(25, &rootNode);
	BST.insert(-2, &rootNode);
	BST.insert(-5, &rootNode);
	printTree(rootNode);
	
	
	BST.remove(-4, &rootNode);
	printTree(rootNode);
	//std::cout << BST.search(-4, &rootNode);
	//printTree(rootNode);

	//// Test search
	//Node* search_result = BST.search(2, &rootNode);
	//std::cout << "Search Result: ";
	//printTree(*search_result);
	//printTree(BST.getRootNode());
	//

	//// Test Destructor
	//BST.~Tree();
	//printTree(rootNode);

	return 0;
}

void printTree(Node root)
{
	std::cout << std::endl;
	if (root.left)
	{
		std::cout << "Key: ";
		std::cout << root.key;
		std::cout << "\tLeft : ";
		std::cout << root.left->key;
		std::cout << "\tParent: ";
		if(root.parent) std::cout << root.parent->key;
		printTree(*root.left);
	}
	if (root.right)
	{
		std::cout << "Key: ";
		std::cout << root.key;
		std::cout << "\tRight : ";
		std::cout << root.right->key;
		std::cout << "\tParent: ";
		if(root.parent) std::cout << root.parent->key;
		printTree(*root.right);
	}
}