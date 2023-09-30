#include <iostream>
#include "BinarySearch.h"
#include <stdlib.h>
#include <algorithm>

template <int N>
int* generateArray();
void printArray(int* arr, int size);

int main()
{
	const int size = 20;
	int* arr = generateArray<size>();
	
	// print array
	std::cout << "Original Array: ";
	printArray(arr, size);

	// sort the generated array
	std::sort(arr, arr + size);
	
	// print array
	std::cout << "Sorted Array: ";
	printArray(arr, size);

	// search
	BinarySearch BS_alg;
	std::cout << "Idx of the target number : ";
	std::cout << BS_alg.search(arr, size, arr[4]);
	std::cout << "\tNumber of iterations : ";
	std::cout << BS_alg.getNum_iter();
	
}

template <int N>
int* generateArray()
{
	int *arr = new int[N];

	// seed the random number generator
	srand(time(NULL));

	// generate a random element for each element in the array
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() / 100;
	}

	return arr;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}