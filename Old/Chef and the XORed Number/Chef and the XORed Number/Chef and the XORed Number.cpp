// Chef and the XORed Number.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>

int main()
{
	int T;
	unsigned long N, i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lu", &N);
		if (N == 1)
		{
			printf("2\n");
		}
		else
		{
			if (floor(log2(N + 1)) == ceil(log2(N + 1)))
			{
				printf("%lu\n", N / 2);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
    return 0;
}

