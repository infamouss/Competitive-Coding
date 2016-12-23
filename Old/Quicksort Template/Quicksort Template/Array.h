#pragma once


template <class T>
class Array
{
private:
	int N;
	T* A;
public:
	Array(int n);
	~Array();
	int Partiton(int low, int high);
	void QuickSort(int low, int high);
	void QuickSort();
	void Scan();
	void Print();
};

