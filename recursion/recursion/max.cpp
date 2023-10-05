#include "functions.h"

int maxArray(int *arr, int size, int i, int max)
{
	if (size == 0) return 0;
	if (i == size) return max;

	if (arr[i] > max) max = arr[i];
	return maxArray(arr, size, i + 1, max);
}