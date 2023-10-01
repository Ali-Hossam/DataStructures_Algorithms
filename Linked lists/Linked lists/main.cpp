#include <iostream>
#include "LinkedList.h"

template<typename T>
void printLinkedList(LinkedList<T> &list);

int main()
{
	Node<int> *head = new Node <int>;
	head->data = 5;
	
	LinkedList<int> list(head);
	list.insert(4);
	list.insert(9);
	list.insert(7);
	list.insert(8);
	list.insert(2);
	printLinkedList(list);
	list.remove(7);
	printLinkedList(list);
	list.remove(2);
	printLinkedList(list);
	std::cout << list.search(1);
	return 0;
}

template<typename T>
void printLinkedList(LinkedList<T> &list)
{
	Node<int>* node = list.getHead();
	if (node)
	{
		while (node->next)
		{
			std::cout << node->data;
			node = node->next;
		}
		std::cout << node->data;
	}
	std::cout << "\tHead: " << list.getHead()->data;
	std::cout << "\tTail: " << list.getTail()->data;
	std::cout << "\n";
}