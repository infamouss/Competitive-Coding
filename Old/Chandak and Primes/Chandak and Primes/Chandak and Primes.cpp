// Chandak and Primes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

bool isComp[1000001] = { false };
long count[1000001] = { 0 };

void SOE(long N)
{
	long i, j;
	isComp[0] = isComp[1] = false;
	isComp[2] = false;
	for (i = 2;i <= N;)
	{
		for (j = 2 * i;j <= N;j += i)
			isComp[j] = true;
		i++;
		while (isComp[i])
		{
			i++;
		}
	}
}



void countPrimes(long N)
{
	long i;
	for (i = 2;i <= N;i++)
	{
		count[i] = count[i - 1] + ((isComp[i]) ? 0 : 1);
	}
}




int main()
{
	int T, i;
	long low[10000], high[10000], limit = 0;
	scanf("%d", &T);

	for (i = 0;i < T;i++)
	{
		scanf("%ld%ld", &low[i], &high[i]);
		if (high[i] > limit)
		{
			limit = high[i];
		}
	}
	SOE(limit);
	countPrimes(limit);


	for (i = 0;i < T;i++)
	{
		printf("%ld\n", count[high[i]] - count[low[i] - 1]);
	}

	return 0;
}

