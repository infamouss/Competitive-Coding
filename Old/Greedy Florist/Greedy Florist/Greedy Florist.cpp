// Greedy Florist.cpp : Defines the entry polong for the console application.
// url : https://www.hackerrank.com/challenges/greedy-florist

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
	int N, K, i, n;
	long a[100], ans = 0;
	scanf("%d%d", &N, &K);
	for (i = 0;i < N;i++)
	{
		scanf("%ld", &a[i]);
	}
	heapSort(a, N);
	n = N;
	for (i = 0;i < n;i++, N--)
	{
		ans += ((N - 1) / K + 1)*a[i];
	}
	printf("%ld", ans);
	return 0;
}

