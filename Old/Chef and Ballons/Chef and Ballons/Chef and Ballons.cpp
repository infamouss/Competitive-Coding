// Chef and Ballons.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/APRIL16/problems/CHBLLNS

#include <stdio.h>


int main()
{
	int T;
	long long R, G, B, K, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld", &R, &G, &B, &K);
		ans = 1;
		if (K <= R)
			ans += (K - 1);
		else
			ans += R;
		if (K <= G)
			ans += (K - 1);
		else
			ans += G;
		if (K <= B)
			ans += (K - 1);
		else
			ans += B;
		printf("%lld\n", ans);
	}
	return 0;
}

