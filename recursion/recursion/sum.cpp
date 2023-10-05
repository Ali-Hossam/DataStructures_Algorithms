#include "functions.h"
int sumArray(int* arr, int size, int i)
{
	if (!size) return 0;
	if (i == size - 1) { return arr[i]; }
	return arr[i] + sumArray(arr, size, i+1);
}