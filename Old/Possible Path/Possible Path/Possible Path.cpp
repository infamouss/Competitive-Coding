// Possible Path.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

long long GCD(long long a, long long b)
{
	long long retval;
	if (a%b == 0)
	{
		retval = b;
	}
	else
	{
		retval = GCD(b, a%b);
	}
	return retval;
}


int main()
{
	int T;
	long long a, b, x, y;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
		printf("%s\n", (GCD(a, b) == GCD(x, y)) ? "YES" : "NO");
	}
	return 0;
}

