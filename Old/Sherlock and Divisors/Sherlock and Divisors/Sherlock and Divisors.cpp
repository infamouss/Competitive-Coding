// Sherlock and Divisors.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int numDivisors(long *n, int num)
{
	int count = 0;
	long N = *n;
	while (N%num == 0)
	{
		count++;
		N = N / num;
	}
	*n = N;
	return count;
}





int main()
{
	int T, numDivs, i;
	long N;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		if (N % 2 != 0)
		{
			printf("0\n");
		}
		else
		{
			numDivs = 1;
			i = 2;
			N = N / 2;
			while (N != 1)
			{
				if (N%i == 0)
				{
					numDivs = numDivs*(numDivisors(&N, i) + 1);
				}
				i++;
			}
			printf("%d\n", numDivs);
		}
	}
	return 0;
}

