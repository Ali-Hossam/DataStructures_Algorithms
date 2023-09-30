struct Node
{
	int key;
	struct Node *left = nullptr, *right = nullptr;
	struct Node* parent = nullptr;
	// struct keyword in not necessary, but it is used to clarify that
	// the variable is a pointer
};

