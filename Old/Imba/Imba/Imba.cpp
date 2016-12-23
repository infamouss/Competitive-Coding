// Imba.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long N, i, j, k;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		if (N % 2 == 0)
		{
			i = N / 2;
			j = N / 2 + 1;
			for (k = 0;k < N;k++)
			{
				if (k % 2 == 0)
				{
					printf("%ld ", i);
					i--;
				}
				else
				{
					printf("%ld ", j);
					j++;
				}
			}
		}
		else
		{
			i = N / 2 + 1;
			j = N / 2;
			for (k = 0;k < N;k++)
			{
				if (k % 2 == 0)
				{
					printf("%ld ", i);
					i++;
				}
				else
				{
					printf("%ld ", j);
					j--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

