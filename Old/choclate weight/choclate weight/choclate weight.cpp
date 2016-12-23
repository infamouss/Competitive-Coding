// choclate weight.cpp : Defines the entry point for the console application.
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



int binarySearch(int array[], int num, int start, int end)
{
	int mid = (start + end) / 2;
	if (start > end)
	{
		return -1;
	}
	if (num == array[mid])
	{
		return mid;
	}
	else if (num < array[mid])
	{
		return binarySearch(array, num, start, mid - 1);
	}
	else
	{
		return binarySearch(array, num, mid + 1, end);
	}
}




int main()
{
	int N, arr[10000], q, i, weight, j, flag;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	heapSort(arr, N);

	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &weight);
		if (binarySearch(arr, weight, 0, N - 1) != -1)
		{
			printf("I Like You\n");
		}
		else
		{
			j = flag = 0;
			while (arr[j] < weight && j < N && flag == 0)
			{
				if (binarySearch(arr, weight - arr[j], 0, N - 1) != -1)
				{
					if (binarySearch(arr, weight - arr[j], 0, N - 1) == j)
					{
						printf("I Hate You\n");
					}
					else
						printf("I Like You\n");
					flag = 1;
				}
				j++;
			}
			if (flag == 0)
			{
				printf("I Hate You\n");
			}
		}
	}


	return 0;
}

