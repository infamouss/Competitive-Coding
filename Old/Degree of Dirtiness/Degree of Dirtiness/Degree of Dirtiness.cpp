// Degree of Dirtiness.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T, N, tmp;
	long M;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%ld", &N, &M);
		
		if (N % 2 == 0)
		{
			M = M - 1;
			if ((M%N) % 2 == 0)
			{
				printf("%ld", (M%N) / 2 + 1);
			}
			else
			{
				printf("%ld", N - (M%N) / 2);
			}
		}
		else
		{
			M = M - 1;
			if ((M / N) % 2 == 0)
			{
				if ((M%N) % 2 == 0)
				{
					printf("%ld", (M%N) / 2 + 1);
				}
				else
				{
					printf("%ld", N - (M%N) / 2);
				}
			}
			else
			{
				if ((M%N) % 2 == 0)
				{
					printf("%ld", N - (M%N) / 2);
				}
				else
				{
					printf("%ld", (M%N) / 2);
				} 
			}
		}
		printf(" %ld\n", M / N);
	}
	return 0;
}

