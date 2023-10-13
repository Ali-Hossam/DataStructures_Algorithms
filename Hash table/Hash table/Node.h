#include <string>

// Linked list node
struct Node
{
public:
	std::string name;
	float price;
	Node* nextNode = nullptr;
	Node* parentNode = nullptr;

};