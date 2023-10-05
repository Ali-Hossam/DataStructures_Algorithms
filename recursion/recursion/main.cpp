#include "functions.h"
#include <iostream>

int main()
{
	int arr[] = { 2, 32, 33, 44, 12, 282 };
	int size = sizeof(arr) / sizeof(int);
	int sum_ = sumArray(arr, size);
	int count = countArray(arr, arr[size - 1]);
	int max = maxArray(arr, size);

	std::cout << "Sum: " << sum_ << "\tPredicted Count: " << count << "\tTrue Count: " << size;
	std::cout << "\nMax number in the array: " << max;
	
	return 0;
}