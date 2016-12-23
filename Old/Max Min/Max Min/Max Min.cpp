// Max Min.cpp : Defines the entry polong for the console application.
//

#include <stdio.h>


void insertHeap(long current, long low, long high, long a[])
{
	long large, done = 0;
	large = 2 * low + 1;
	while (large <= high && !done)
	{
		if (large < high && a[large] < a[large + 1])
		{
			large++;
		}
		if (current > a[large])
		{
			done = 1;
		}
		else
		{
			a[low] = a[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	a[low] = current;
}

void buildHeap(long a[], long n)
{
	long low;
	for (low = n / 2 - 1; low >= 0; low--)
	{
		insertHeap(a[low], low, n - 1, a);
	}
}

void heapSort(long a[], long n)
{
	long lu, current;
	buildHeap(a, n);
	for (lu = n - 1; lu >= 1; lu--)
	{
		current = a[lu];
		a[lu] = a[0];
		insertHeap(current, 0, lu - 1, a);
	}
}



int main()
{
	long N, arr[100000], K, i, min;
	scanf("%ld%ld", &N, &K);
	for (i = 0;i < N;i++)
		scanf("%ld", &arr[i]);
	heapSort(arr, N);
	min = arr[K - 1] - arr[0];
	for (i = K;i < N;i++)
		if (arr[i] - arr[i - K + 1] < min)
			min = arr[i] - arr[i - K + 1];
	printf("%ld", min);

	return 0;
}

