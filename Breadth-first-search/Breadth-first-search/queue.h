#include <vector>
#include "node.h"

class queue
{
	int n = 0;	// number of values in the queue
	std::vector<Node*> arr;

public:
	void enqueue(Node *nodeToAdd);
	Node* dequeue();
	bool isEmpty() const;
	int getLength() const;
};