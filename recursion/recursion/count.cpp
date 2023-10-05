#include "functions.h"

int countArray(int* arr, int tail, int i)
{
	if (arr[i] == tail) { return i + 1; }
	return countArray(arr, tail, i + 1);
}