// Prime Generator.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <cmath>

bool isPrime(long long n)
{
	long j;
	float sqr = sqrt(n);
	if (n % 2 == 0)
		return false;
	for (j = 3;j <= sqr;j += 2)
	{
		if (n%j == 0)
			return false;
	}
	return true;
}



int main()
{
	int T;
	long long m, n, i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &m, &n);
		if (m <= 2)
		{
			printf("2\n");
			for (i = 3;i <= n;i += 2)
			{
				if (isPrime(i))
				{
					printf("%lld\n", i);
				}
			}
		}
		else
		{
			for (i = m;i <= n;i++)
			{
				if (isPrime(i))
				{
					printf("%lld\n", i);
				}
			}
		}
		printf("\n");
	}
	return 0;
}