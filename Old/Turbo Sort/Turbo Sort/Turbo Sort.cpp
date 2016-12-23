// Turbo Sort.cpp : Defines the entry point for the console application.
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



long arr[1000000];
int main()
{
	long i, n;
	scanf("%ld", &n);
	for (i = 0;i < n;i++)
	{
		scanf("%ld", &arr[i]);
	}
	heapSort(arr, n);
	for (i = 0;i < n;i++)
	{
		printf("%ld\n", arr[i]);
	}
    return 0;
}

