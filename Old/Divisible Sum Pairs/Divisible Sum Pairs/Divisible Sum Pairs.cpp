// Divisible Sum Pairs.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/w20/challenges/divisible-sum-pairs

#include <stdio.h>


int main()
{
	int N, K, ip[100], tmp, i, j, ans = 0;
	scanf("%d%d", &N, &K);
	for (i = 0;i < N;i++)
	{
		scanf("%d", &tmp);
		ip[i] = tmp%K;
	}

	for (i = 0;i < N - 1;i++)
	{
		for (j= i + 1;j < N;j++)
		{
			if (ip[i] + ip[j] == 0 || ip[i] + ip[j] == K)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

