// Chandu and his Girlfriend.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>



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
	long T, n;
	long* a;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%ld", &n);
		a = (long*)malloc(sizeof(long)*n);
		for (int i = 0;i < n;i++)
		{
			scanf("%ld", &a[i]);
		}
		heapSort(a, n);
		for (int i = n-1;i >= 0;i--)
		{
			printf("%d ", a[i]);
		}
		free(a);
		printf("\n");
	}
	return 0;
}

