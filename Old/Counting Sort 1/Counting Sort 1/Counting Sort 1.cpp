// Counting Sort 1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


int main()
{
	long count[100] = {0}, n, i;
	int *arr;

	scanf("%ld", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
		count[arr[i]]++;
	}

	for (i = 0;i < 100;i++)
	{
		printf("%ld ", count[i]);
	}
	free(arr);
	return 0;
}

