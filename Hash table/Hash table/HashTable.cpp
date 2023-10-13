#include "HashTable.h"


HashTable::~HashTable()
{
	for (auto& kv : table)
	{
		delete kv.second;
	}
}

void HashTable::search(std::string name, Node*& searchResult, List*& searchResultList)
{
	// if the key is found, target list will store the list that
	// has the key.
	// search for the first char
	char firstLetter = name[0];
	auto iter = table.find(firstLetter);

	if (iter != table.end())
	{
		searchResult = table.at(firstLetter)->search(name);
		searchResultList = iter->second;
	}
	else
	{
		searchResultList = nullptr;
		searchResult = nullptr;
	}
}

HashTable::HashTable()
{
}

void HashTable::addItem(std::string name, float price)
{
	// if the item is found change it's price only
	char firstLetter = name[0];
	Node* result;
	List* resultList;
	search(name, result, resultList);
	if (result) { result->price = price; }
	else
	{
		// check if the first letter is in the map
		if (resultList)
		{
			resultList->add(name, price);
		}
		else
		{
			List *newList = new List{ name, price };
			table.insert(std::make_pair(firstLetter, newList));

		}
	}
}

void HashTable::removeItem(std::string name)
{
	// if the item exists delete it from the linked list
	Node* result;
	List* resultList;
	search(name, result, resultList);
	if (result)
	{
		resultList->remove(name);
	}
}

float HashTable::getPrice(std::string name)
{
	Node* result;
	List* resultList;
	search(name, result, resultList);
	if (result) { return result->price; }
	return 0;
}

std::map<char, List*> HashTable::getTable() const
{
	return table;
}