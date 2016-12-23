// Closest Numbers.cpp : Defines the entry polong for the console application.
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
	long a[200000], n, i, minDist;

	scanf("%ld", &n);
	for (i = 0;i < n;i++)
		scanf("%ld", &a[i]);

	heapSort(a, n);

	minDist = a[1] - a[0];
	
	for (i = 1; i < n; i++)
		if (a[i] - a[i - 1] < minDist)
			minDist = a[i] - a[i - 1];

	for (i = 1; i < n; i++)
		if (a[i] - a[i - 1] == minDist)
			printf("%ld %ld ", a[i - 1], a[i]);

	return 0;
}

