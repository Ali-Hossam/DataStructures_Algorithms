#include "QuickSort.h"
#include <iostream>

void printArray(int* arr, int size);
int main()
{
	int arr[] = { 2 , 3, 1, 0, 32, 328, 12, 58 , 10, 1400, 283, 21, -1, -58, 21};
	int size = sizeof(arr) / sizeof(int);
	QuickSort sortAlgorithm;
	printArray(arr, size);
	sortAlgorithm.sort(arr, size);
	printArray(arr, size);
	return 0;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "   ";
	}
	std::cout << std::endl;
}