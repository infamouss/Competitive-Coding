// Rangoli and Jugs.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

long long GCD(long long a, long long b)
{
	return (a%b == 0) ? b : GCD(b, a%b);
}

int main()
{
	long T;
	unsigned long long a, b, x;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%llu%llu%llu", &a, &b, &x);
		printf("%s\n", (x%GCD(a, b)) ? "NO" : "YES");
	}

	return 0;
}

