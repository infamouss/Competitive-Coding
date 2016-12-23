 // Campers.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>


int main()
{
	long N, K, i, ans = 0, tmp;
	int *arr;
	scanf("%ld%ld", &N, &K);
	arr = (int*)malloc(sizeof(int)*(N + 2));
	for (i = 0;i < N+2;i++)
	{
		arr[i] = 0;
	}
	for (i = 0;i < K;i++)
	{
		scanf("%ld", &tmp);
		arr[tmp] = 1;
	}

	for (i = 1;i <= N;i++)
	{
		if (arr[i - 1] == 0 && arr[i + 1] == 0)
		{
			ans++;
			arr[i] = 1;
			i++;
		}
	}
	printf("%ld", ans);
	free(arr);
	return 0;
}