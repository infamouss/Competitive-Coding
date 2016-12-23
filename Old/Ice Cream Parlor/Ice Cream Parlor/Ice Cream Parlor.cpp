// Ice Cream Parlor.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, M, N, C[10000], i, j, flag;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &M, &N);
		flag = 0;
		for (i = 0;i < N;i++)
		{
			scanf("%d", &C[i]);
		}
		for (i = 0;i < N - 1 && flag == 0;i++)
		{
			for (j = i + 1;j < N&&flag == 0;j++)
			{
				if (C[i] + C[j] == M)
				{
					printf("%d %d\n", i + 1, j + 1);
					flag = 1;
				}
			}
		}
	}
	return 0;
}

