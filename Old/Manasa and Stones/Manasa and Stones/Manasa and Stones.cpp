// Manasa and Stones.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>



int main()
{
	int T, n, a, b, min, max, i, diff;
	long sum;

	scanf("%d", &T);
	while (T--)
	{
		sum = 0;
		scanf("%d%d%d", &n, &a, &b);
		if (n == 1)
		{
			printf("0 ");
		}
		else
		{
			if (a < b)
			{
				min = a;
				max = b;
			}
			else
			{
				min = b;
				max = a;
			}
			sum = (n - 1)*min;
			diff = max - min;
			if (diff == 0)
			{
				printf("%ld ", sum);
			}
			else
			{
				for (i = 0;i < n;i++)
				{
					printf("%ld ", sum);
					sum += diff;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

