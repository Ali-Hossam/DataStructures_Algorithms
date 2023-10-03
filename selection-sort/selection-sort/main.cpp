#include "selection-sort.h"
#include <iostream>

void printArr(int* arr, int size);
int main()
{
	int arr[10] = { 2, 12, 8, 24, 0, -1, 4, 5, 77, 21 };
	printArr(arr, 10);
	selection_sort(arr, 10);
	printArr(arr, 10);
	return 0;
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}