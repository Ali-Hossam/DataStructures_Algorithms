#include "List.h"
#include <map>

// an implementation of a gracoery store datastructure that 
// stores items like (groceries) in a hash table (map) where each
// key of the map is a letter in the english alphabit, and the value
// of the map is a linked list.

class HashTable
{
private:
	std::map <char, List*> table;
	void search(std::string name, Node*& searchResult, List*& searchResultList);

public:
	HashTable();
	void addItem(std::string name, float price);
	void removeItem(std::string name);
	float getPrice(std::string name);
	std::map<char, List*> getTable() const;
	~HashTable();
};