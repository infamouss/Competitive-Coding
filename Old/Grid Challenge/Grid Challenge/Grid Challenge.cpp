// Grid Challenge.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/grid-challenge

#include <stdio.h>

void insertHeap(int current, int low, int high, char a[])
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

void buildHeap(char a[], int n)
{
	int low;
	for (low = n / 2 - 1; low >= 0; low--)
	{
		insertHeap(a[low], low, n - 1, a);
	}
}

void heapSort(char a[], int n)
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
	int T, N, i, j;
	bool flag;
	char ip[100][101];
	scanf("%d", &T);
	while (T--)
	{
		flag = true;
		scanf("%d", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%s", ip[i]);
			heapSort(ip[i], N);
		}
		for (i = 0;i < N&&flag;i++)
		{
			for (j = 0;j < N - 1&&flag;j++)
			{
				if (ip[j][i] > ip[j + 1][i])
				{
					flag = false;
				}
			}
		}
		printf("%s\n", (flag) ? "YES" : "NO");
	}
	return 0;
}

