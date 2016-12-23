// Almost Sorted Permutation.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

unsigned long arr[1000000];

int main()
{
	int T, flag;
	unsigned long N, i, prev;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lu", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%lu", &arr[i]);
		}
		prev = 0;
		flag = 0;
		for (i = 1;i < N&&flag == 0;i++)
		{
			if (i - prev == 1)
			{
				if (arr[prev] < arr[i])
				{
					prev = i;
				}
			}
			else
			{
				if (arr[prev] < arr[i])
				{
					prev = i;
				}
				else
				{
					flag = 1;
				}
			}
		}
		printf("%s\n", (flag) ? "NO" : "YES");
	}
	return 0;
}

