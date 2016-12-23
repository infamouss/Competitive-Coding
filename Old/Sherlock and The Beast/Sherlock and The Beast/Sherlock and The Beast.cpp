// Sherlock and The Beast.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, N, i, j, done;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		done = 0;
		for (i = 0;i <= N && done == 0;i+=5)
		{
			if ((N - i) % 3 == 0)
			{
				done = 1;
			}
		}
		if (done == 0)
		{
			printf("-1");
		}
		else
		{
			i = i - 5;
			for (j = 1;j <= N - i;j++)
			{
				printf("5");
			}
			while (i--)
			{
				printf("3");
			}
		}
		printf("\n");
	}
	return 0;
}

