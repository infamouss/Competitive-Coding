// maximize the sum.cpp : Defines the entry point for the console application.
// url:https://www.codechef.com/MARCH16/problems/MAXISUM

#include <stdio.h>

long long A[100000];

int main()
{
	int T;
	long long N, tmp, i, max, min, maxI, minI;
	long long ans, K;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &N, &K);
		for (i = 0;i < N;i++)
		{
			scanf("%lld", &A[i]);
		}
		scanf("%lld", &tmp);
		max = min = tmp;
		maxI = minI = 0;
		ans = tmp*A[0];
		for (i = 1;i < N;i++)
		{
			scanf("%lld", &tmp);
			if (tmp < min)
			{
				min = tmp;
				minI = i;
			}
			if (tmp > max)
			{
				max = tmp;
				maxI = i;
			}
			ans += tmp*A[i];
		}
		if (max > -min)
		{
			ans += max*K;
		}
		else
		{
			ans -= min*K;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

