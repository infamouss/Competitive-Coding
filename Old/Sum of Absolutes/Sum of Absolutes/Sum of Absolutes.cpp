// Sum of Absolutes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long N, i, Q, L, R;
	int arr[100000], tmp;
	scanf("%ld%ld", &N, &Q);
	scanf("%d", &tmp);
	if (tmp % 2 == 0)
	{
		arr[0] = 0;
	}
	else
	{
		arr[0] = 1;
	}
	for (i = 1;i < N;i++)
	{
		scanf("%d", &tmp);
		if (tmp % 2 == 0)
		{
			arr[i] = arr[i-1];
		}
		else
		{
			arr[i] = arr[i - 1] + 1;
		}
	}
	for (i = 0;i < Q;i++)
	{
		scanf("%ld%ld", &L, &R);
		if (L == 1)
		{
			if (arr[R - 1] % 2 == 0)
			{
				printf("Even\n");
			}
			else
			{
				printf("Odd\n");
			}
		}
		else
		{
			if ((arr[R - 1] - arr[L - 2]) % 2 == 0)
			{
				printf("Even\n");
			}
			else
			{
				printf("Odd\n");
			}
		}
	}
	return 0;
}

