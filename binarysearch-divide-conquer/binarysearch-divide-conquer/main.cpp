#include "Bsearch.h"
#include <iostream>

int main()
{
	int arr[] = { 2, 3, 4, 18, 23, 40, 50, 55, 77, 88};
	int key = 2;
	int head = 0;
	int size = sizeof(arr) / sizeof(int);
	int tail = head + size - 1;
	
	int idx = search(arr, size, key, head, tail);
	std::cout << "Search for: " << key << "\tFound at: " 
		<< idx << "\tKey at the found idx: " << arr[idx];

	return 0;
}