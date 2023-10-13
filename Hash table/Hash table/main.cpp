#include <iostream>
#include "HashTable.h"

void printTable(HashTable& table);
int main()
{
	HashTable table;
	table.addItem("Banana", 20);
	table.addItem("tnanana", 20);
	table.addItem("Bana", 30);
	table.addItem("sanana", 20);
	table.addItem("anana", 20);
	printTable(table);
	table.removeItem("Bana");
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