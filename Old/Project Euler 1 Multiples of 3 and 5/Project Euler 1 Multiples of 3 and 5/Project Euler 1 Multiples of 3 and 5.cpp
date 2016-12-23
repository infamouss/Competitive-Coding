// Project Euler 1 Multiples of 3 and 5.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
	unsigned long T, N, i, n;
	unsigned long long sum;
	scanf("%lu", &T);
	while (T--)
	{
		scanf("%lu", &N);
		n = (N - 1) / 3;
		sum = 3 * n*(n + 1) / 2;
		n = (N - 1) / 15;
		sum-=15* n*(n + 1) / 2;
		n = (N - 1) / 5;
		sum+= 5 * n*(n + 1) / 2;
		printf("%llu\n", sum);
	}
	




	return 0;
}

