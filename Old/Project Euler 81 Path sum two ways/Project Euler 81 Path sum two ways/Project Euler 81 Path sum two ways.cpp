// Project Euler 81 Path sum two ways.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

unsigned long arr[1000][1000];

int main()
{
	int N, i, j;
	scanf("%d", &N);
	scanf("%ld", &arr[0][0]);
	for (i = 1;i < N;i++)
	{
		scanf("%ld", &arr[0][i]);
		arr[0][i] += arr[0][i - 1];
	}
	for (i = 1;i < N;i++)
	{
		scanf("%ld", &arr[i][0]);
		arr[i][0] += arr[i - 1][0];
		for (j = 1;j < N;j++)
		{
			scanf("%ld", &arr[i][j]);
			arr[i][j] += (arr[i - 1][j] < arr[i][j - 1]) ? arr[i - 1][j] : arr[i][j - 1];
		}
	}
	printf("%ld", arr[N - 1][N - 1]);
	return 0;
}

