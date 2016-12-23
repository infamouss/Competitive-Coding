// Chain of Doughnuts.cpp : Defines the entry polong for the console application.
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
	int T;
	long N, numPiecees, sizes[20000], i, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld%ld", &N, &numPiecees);
		ans = 0;
		for (i = 0;i < numPiecees;i++)
		{
			scanf("%ld", &sizes[i]);
		}
		heapSort(sizes, numPiecees);
		i = 0;
		while (numPiecees != 1)
		{
			if (sizes[i] + 1 <= numPiecees - 1)
			{
				numPiecees -= (1 + sizes[i]);
				ans += sizes[i];
			}
			else
			{
				ans += (numPiecees - 1);
				numPiecees = 1;
			}
			i++;
		}
		printf("%ld\n", ans);
	}
    return 0;
}

