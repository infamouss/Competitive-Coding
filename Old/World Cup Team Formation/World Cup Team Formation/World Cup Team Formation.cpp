// World Cup Team Formation.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


void insertHeap(int current, int low, int high, int a[])
{
	int large, done = 0;
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

void buildHeap(int a[], int n)
{
	int low;
	for (low = n / 2 - 1; low >= 0; low--)
	{
		insertHeap(a[low], low, n - 1, a);
	}
}

void heapSort(int a[], int n)
{
	int lu, current;
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
	int a[10], i;
	for (i = 0;i < 10;i++)
	{
		scanf("%d", &a[i]);
	}
	heapSort(a, 10);
	printf("%d\n", a[9] + a[7] + a[5]);
	



    return 0;
}

