// Tournament.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/ZCOPRAC/problems/ZCO13001

#include <stdio.h>

long freq[1001] = { 0 };

int main()
{
	long long N, i, j, ans = 0;
	int strength, diff;
	scanf("%lld", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%d", &strength);
		freq[strength]++;
	}
	for (i = 1;i < 1000;i++)
	{
		for (j = i + 1;j <= 1000;j++)
		{
			ans += freq[i] * freq[j] * (j - i);
		}
	}
	printf("%lld", ans);
	return 0;
}

