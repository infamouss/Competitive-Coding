// Project Euler 5 Smallest multiple.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int gcd(int a, int b)
{
	if (a%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a%b);
	}
}


int main()
{
	int T, N;
	long ans;
	scanf("%d", &T);	
	while (T--)
	{
		scanf("%d", &N);
		ans = N;
		while (--N)
		{
			ans = ans*N / gcd(ans, N);
		}
		printf("%ld\n", ans);
	}
	return 0;
}

