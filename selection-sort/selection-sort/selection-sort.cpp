#include "selection-sort.h"
void selection_sort(int* arr, int size)
{
	int minIdx;
	int swap;
	for (int i = 0; i < size - 1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIdx]) { minIdx = j; }
		}
		swap = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = swap;
	}
}

