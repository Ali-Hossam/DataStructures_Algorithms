#include "Bsearch.h"

int search(int* arr, int size, int key, int head, int tail)
{
	int mid;
	if (head > tail) return -1;
	mid = (head + tail) / 2;

	if (arr[mid] == key) return mid;
	else if (arr[mid] > key) tail = mid - 1;
	else head = mid + 1;

	return search(arr, size, key, head, tail);
}