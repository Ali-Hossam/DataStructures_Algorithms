#include "Tree.h"
Tree::Tree(Node& rootNode)
{
	root = &rootNode;
	isEmpty = true;
}

Tree::~Tree() 
{
	clearNode(root);
}

void Tree::clearNode(Node* node)
{
	if (!node->left && !node->right) { delete node; }
	else
	{
		if (node->left)
		{
			clearNode(node->left);
		}
		if (node->right)
		{
			clearNode(node->right);
		}
	}

}


Node Tree::insert(int key, Node* node)
{
	if (isEmpty)
	{
		node->key = key;
		isEmpty = false;
	}
	else
	{
		if (key < node->key)
		{
			if (node->left != nullptr)
			{
				insert(key, node->left);
			}
			else
			{
				node->left = new Node;
				node->left->key = key;
				node->left->parent = node;
				return *node;
			}
			
		}
		else if (key > node->key)
		{
			if (node->right != nullptr)
			{
				insert(key, node->right);
			}
			else
			{
				node->right = new Node;
				node->right->key = key;
				node->right->parent = node;
				return *node;
			}
		}
	}
};

Node Tree::getRootNode() const { return *root; }

Node* Tree::search(int key, Node* node)
{
	if (key == node->key) { return node; }
	else if (key < node->key)
	{
		if (node->left) { search(key, node->left); }
		else { return nullptr; }
	}
	else if (key > node->key)
	{
		if (node->right) { search(key, node->right); }
		else { return nullptr; }
	}
}

Node* Tree::remove(int key, Node* node)
{
	Node* nodeRM = search(key, node);
	if (!nodeRM) return nullptr;

	if (!nodeRM->left && !nodeRM->right)
	{ 
		if (nodeRM->parent->left) { nodeRM->parent->left = nullptr; }
		else if (nodeRM->parent->right) { nodeRM->parent->right= nullptr; }
	}
	else if (nodeRM->left && nodeRM->right)
	{
		Node* successor = inOrderSuccessor(root->key, root, NULL, key);
		if (!successor) return nullptr;
		if (nodeRM->parent->left)
		{
			if (nodeRM->parent->left == nodeRM)
			{
				nodeRM->parent->left = successor;
			}
		}
		else if (nodeRM->parent->right)
		{
			if (nodeRM->parent->right == nodeRM)
			{
				nodeRM->parent->right = successor;
			}
		}
		successor->parent = nodeRM->parent;
		
		if (nodeRM->left)
		{
			if (nodeRM->left != successor)
			{
				successor->left = nodeRM->left;
				nodeRM->left->parent = successor;
			}
		}
		if (nodeRM->right)
		{
			if (nodeRM->right != successor)
			{
				successor->right = nodeRM->right;
				nodeRM->right->parent = successor;
			}
		}
	}
	else if (nodeRM->left)
	{
		// replace the node with it's child (left)
		if (nodeRM->parent->left == nodeRM)
		{
			nodeRM->parent->left = nodeRM->left;
		}
		else if (nodeRM->parent->right == nodeRM)
		{
			nodeRM->parent->right = nodeRM->left;
		}
		nodeRM->left->parent = nodeRM->parent;
	}
	else if (nodeRM->right)
	{
		if (nodeRM->parent->left == nodeRM)
		{
			nodeRM->parent->left = nodeRM->right;
		}
		else if (nodeRM->parent->right == nodeRM)
		{
			nodeRM->parent->right = nodeRM->right;
		}
		nodeRM->right->parent = nodeRM->parent;
	}
	nodeRM->left = nullptr;
	nodeRM->right = nullptr;
	clearNode(nodeRM);
	return root;
	
}

Node* Tree::inOrderSuccessor(int currentKey, Node* node, int pastKey, int keySearch)
{
	// inorder successor searches the most left nodes, then middle node the the right
	// one,  however, here we search the most right nodes first so that the return
	// becomes the requested node.
	// note that: if it was implemented like normal inorder successor the pastkey would 
	// equal the requested key at node -5 when we are entering the search, not in the back 
	// track of the recursion.

	if (node->right)
	{
		Node* rightResult = inOrderSuccessor(node->right->key,
			node->right, currentKey, keySearch);
		if (rightResult) { return rightResult; }
	}

	if (pastKey == keySearch) { return node; }
	
	if (node->left) 
	{
		Node* leftResult = inOrderSuccessor(node->left->key, 
			node->left, currentKey, keySearch); 
		if (leftResult) { return leftResult; }
	}
	return nullptr;
}