// Sharing Candies.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/SNCKPA16/problems/GIVCANDY

#include <stdio.h>

typedef long long int lli;

long long GCD(long long a, long long b)
{
	if (a%b == 0)
	{
		return b;
	}
	return GCD(b, a%b);
}

long long abs(long long a)
{
	return a > 0 ? a : -a;
}


long long min(long long a, long long b)
{
	return a < b ? a : b;
}


int main()
{
	int T;
	long long a, b, c, d, ab, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		a %= c;
		b %= d;
		ab = abs(a - b) % GCD(c, d);
		ans = min(ab, GCD(c, d) - ab);
		printf("%lld\n", ans);
	}
	return 0;
}

