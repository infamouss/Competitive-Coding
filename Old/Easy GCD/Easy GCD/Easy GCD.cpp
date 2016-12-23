// Easy GCD.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/101hack38/challenges/easy-gcd-1

#include <stdio.h>

unsigned long long GCD(unsigned long long a, unsigned long long b)
{
	if (a%b == 0)
		return b;
	else
		return GCD(b, a%b);
	return 0;
}




int main()
{
	unsigned long long n, k, a, gcd, i, ans;
	scanf("%llu%llu", &n, &k);
	n--;
	scanf("%llu", &a);
	gcd = a;
	while (n--)
	{
		scanf("%llu", &a);
		gcd = GCD(gcd, a);
	}


	/* (k > gcd)
	{
		for (i = 0;i < gcd;i++)
		{

			if ((k - i) % gcd == 0)
			{
				printf("%llu", k - i);
				return 0;
			}
		}
	}
	else if (k == gcd)
	{
		printf("%llu", k);
	}
	else
		printf("0");*/
	ans = 0;
	for (i = 1;i*i <= gcd;i++)
	{
		if()




	}

	return 0;
}

