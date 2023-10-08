#include "QuickSort.h"

void QuickSort::sort(int *arr, int size)
{
	if (size < 2) { return; }
	int pivot_idx = size - 1;
	int ptr1 = 0;
	int ptr2 = 0, midValue;

	for (int i = 0; i < size; i++)
	{
		if (arr[ptr1] > arr[pivot_idx])
		{

			if (ptr2 == pivot_idx)
			{
				midValue = arr[ptr1];
				arr[ptr1] = arr[pivot_idx];
				arr[pivot_idx] = midValue;
				pivot_idx = ptr1;
			}
			else if (arr[ptr2] < arr[pivot_idx])
			{
				midValue = arr[ptr1];
				arr[ptr1] = arr[ptr2];
				arr[ptr2] = midValue;
				ptr1++;
				ptr2++;
			}
			else
				ptr2++;
		}
		else 
		{
			ptr1++;
			ptr2++;
		}
			
	}


	// sort array in place
  	if (pivot_idx > 0 && pivot_idx < size)
	{
		sort(arr, pivot_idx);
	}
	if (0 <= pivot_idx && pivot_idx < size - 1)
	{
		sort(&arr[pivot_idx + 1], size - pivot_idx - 1);
	}
}