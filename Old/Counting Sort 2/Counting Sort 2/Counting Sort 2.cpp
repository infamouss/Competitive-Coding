// Counting Sort 2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


int main()
{
	long count[100] = { 0 }, n, i;
	int *arr, j;

	scanf("%ld", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
		count[arr[i]]++;
	}

	for (i = 0;i < 100;i++)
	{
		for (j = 0;j < count[i];j++)
		{
			printf("%d ", i);
		}
	}
	free(arr);

	return 0;
}

