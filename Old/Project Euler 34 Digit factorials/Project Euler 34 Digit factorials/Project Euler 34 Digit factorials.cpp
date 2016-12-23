// Project Euler 34 Digit factorials.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	long N, i, tmp;
	long fact[] = { 1,1,2,6,24,120,720,5040,40320,362880 };
	long ans = 0, sum;
	scanf("%ld", &N);
	for (i = 10;i < N;i++)
	{
		tmp = i;
		sum = 0;
		while (tmp != 0)
		{
			sum += fact[tmp % 10];
			tmp = tmp / 10;
		}
		if (sum%i == 0)
		{
			ans += i;
		}
	}
	printf("%ld\n", ans);
	return 0;
}

