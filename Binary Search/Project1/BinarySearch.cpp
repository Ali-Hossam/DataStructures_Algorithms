#include "BinarySearch.h"
BinarySearch::BinarySearch() {}
BinarySearch::~BinarySearch() {}

int BinarySearch::search(int* arr, int size, int num)
{
	/* 
	args:
		size: array size
		num: number to search for in the array
	*/
	
	int mid = 0;
	int low = 0, high = size - 1;
	while (low <= high)
	{
		num_iter++;
		mid = (low + high) / 2;
		if (arr[mid] == num) { return mid; }
		else if (arr[mid] < num)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int BinarySearch::getNum_iter() const { return num_iter; }