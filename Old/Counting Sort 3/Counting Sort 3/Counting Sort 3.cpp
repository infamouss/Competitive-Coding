// Counting Sort 3.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	long count[100] = { 0 }, n, i;
	int *arr;
	char tmp[100];

	scanf("%ld", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0;i < n;i++)
	{
		scanf("%d%s", &arr[i], tmp);
		count[arr[i]]++;
	}

	n = 0;
	for (i = 0;i < 100;i++)
	{
		n += count[i];
		printf("%ld ", n);
	}
	free(arr);

	return 0;
}

