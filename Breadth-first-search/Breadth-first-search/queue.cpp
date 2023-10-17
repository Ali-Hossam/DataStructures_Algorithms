#pragma once
#include "queue.h"

void queue::enqueue(Node *nodeToAdd)
{
	arr.push_back(nodeToAdd);
	n++;
}

Node* queue::dequeue()
{
	Node *node = arr[0];
	arr.erase(arr.begin());	// remove the first element in the queue
	n--;
	return node;
}

bool queue::isEmpty() const 
{ 
	if(!n) 
		return true; 
	return false;
}

int queue::getLength() const
{
	return n;
}
