// Help Watson Escape.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/APRIL16/problems/BIPIN3

#include <stdio.h>


int main()
{
	int T;
	long long N, K, ans, i, mul;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &N, &K);
		ans = K;
		N--;
		mul = K - 1;
		while (N != 0)
		{
			if (N % 2 != 0)
			{
				ans = (ans*mul) % 1000000007;
			}
			mul = (mul*mul) % 1000000007;
			N /= 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

