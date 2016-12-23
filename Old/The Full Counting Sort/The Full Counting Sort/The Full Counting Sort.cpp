// The Full Counting Sort.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct cellType
{
	int data;
	char str[100];
} cell;




void selectionSort(cell a[], long n)
{
	long i, j, minIndex;
	cell tmp;
	for (i = 0; i < n - 1; i++)
	{
		//minIndex = i;

		for (j = i + 1; j < n; j++)
		{
			if (a[i].data > a[j].data)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				//minIndex = j;
			}
		}
		/*if (minIndex != i)
		{
		tmp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = tmp;
		}*/
	}
}



int main()
{
	cell* arr;
	long n, i;
	scanf("%ld", &n);
	arr = (cell*)malloc(sizeof(cell)*n);
	for (i = 0;i < n;i++)
	{
		scanf("%d%s", &arr[i].data, arr[i].str);
	}
	selectionSort(arr, n);

	for (i = 0;i < n;i++)
	{
		printf("%d %s\n", arr[i].data, arr[i].str);
	}

	free(arr);
	return 0;
}

