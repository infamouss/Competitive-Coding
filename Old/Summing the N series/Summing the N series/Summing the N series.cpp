// Summing the N series.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main()
{
	int T;
	long long n, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &n);
		ans = ((n % 1000000007)*(n % 1000000007)) % 1000000007;
		printf("%lld\n", ans);
	}
    return 0;
}

