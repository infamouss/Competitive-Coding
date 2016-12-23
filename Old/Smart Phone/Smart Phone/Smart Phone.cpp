// Smart Phone.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/ZCOPRAC/problems/ZCO14003

#include <stdio.h>

long long arr[500000];

void insertHeap(long long current, long long low, long long high, long long a[])
{
	long long large, done = 0;
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

void buildHeap(long long a[], long long n)
{
	long long low;
	for (low = n / 2 - 1; low >= 0; low--)
	{
		insertHeap(a[low], low, n - 1, a);
	}
}

void heapSort(long long a[], long long n)
{
	long long lu, current;
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
	long long N, i, ans;
	scanf("%lld", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%lld", &arr[i]);
	}
	heapSort(arr, N);
	ans = N*arr[0];
	for (i = 1;i < N;i++)
	{
		if (ans < arr[i] * (N - i))
		{
			ans = arr[i] * (N - i);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

