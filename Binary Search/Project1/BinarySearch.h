#pragma once

class BinarySearch
{
private:
	int num_iter = 0;

public:
	BinarySearch();
	~BinarySearch();
	int search(int*, int, int);
	int getNum_iter() const;
};

