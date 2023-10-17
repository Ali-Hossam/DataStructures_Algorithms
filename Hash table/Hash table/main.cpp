#include <iostream>
#include "HashTable.h"

void printTable(HashTable& table);
int main()
{
	HashTable table;
	table.addItem("Banana", 20.5);
	table.addItem("Potato", 10);
	table.addItem("Tomato", 30);
	table.addItem("Peach", 12);
	table.addItem("Orange", 26);
	printTable(table);
	table.removeItem("Peach");
	printTable(table);
	std::cout << table.getPrice("Banana");
	return 0;
}


void printList(List* list)
{
	Node* node = list->getFirstNode();
	while (node)
	{
		std::cout << node->name << "\t" << node->price << "\t\t";
		node = node->nextNode;
	}
	std::string dashes(20, '-');
	std::cout << std::endl << dashes << std::endl;
}

void printTable(HashTable& table)
{

	for (auto& kv : table.getTable())
	{
		std::cout << kv.first << ":\t";
		printList(kv.second);
	}
	std::string dashes(20, '=');
	std::cout << std::endl << dashes << std::endl;
}