#include "Array.h"


template<class T>
Array<T>::Array(int n)
{
	N = n;
	A = new T[N];
}

template<class T>
Array<T>::~Array()
{
	delete A;
}

template<class T>
int Array<T>::Partiton(int low, int high)
{
	int left = low, right = high;
	T pivot_item = A[low], tmp;
	while (left < right)
	{
		while (A[left] <= pivot_item)
		{
			left++;
		}
		while (A[right] > pivot_item)
		{
			right--;
		}

		if (left < right)
		{
			tmp = A[left];
			A[left] = A[right];
			A[right] = tmp;
		}
	}
	A[low] = A[right];
	A[right] = pivot_item;
	return right;
}

template<class T>
void Array<T>::QuickSort()
{
	QuickSort(0, N - 1);
}

template<class T>
void Array<T>::QuickSort(int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partiton(low, high);
		QuickSort(low, pivot - 1);
		QuickSort(pivot + 1, high);
	}
}

template<class T>
void Array<T>::Scan()
{
	int i = 0;
	cout << "Enter the elements\n";
	for (i = 0;i < N;i++)
	{
		cin >> A[i];
	}
}

template<class T>
void Array<T>::Print()
{
	int i = 0;
	for (i = 0;i < N;i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
