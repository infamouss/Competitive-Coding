// Fair Cut.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/hourrank-12/challenges/fair-cut

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	vector<long long>P(n);
	for (i = 0;i < n;i++)
		scanf("%lld", &P[i]);
	sort(P.begin(), P.end());
	//easy: odd odd,even even

	//odd odd
	long long ans = 0;
	if ((n % 2 == 1 && k % 2 == 1)||(n % 2 == 0 && k % 2 == 0))
	{
		


		for (i = 0;i < n;i++)
		{
			if (i == (n - k) / 2)
			{
				i = (n + k) / 2 - 1;
				continue;
			}
			for (j = (n - k) / 2;j < (n + k) / 2;j++)
			{
				ans += abs(P[i] - P[j]);
			}
		}




	}
	else
	{
		long long ans1 = 0;
		

		for (i = 0;i < n;i++)
		{
			if (i == (n - k) / 2)
			{
				i = (n + k) / 2 - 1;
				continue;
			}
			for (j = (n - k) / 2;j < (n + k) / 2;j++)
			{
				ans1 += abs(P[i] - P[j]);
			}
		}


		for (i = 0;i < n;i++)
		{
			if (i == (n - k + 1) / 2)
			{
				i = (n + k-1) / 2;
				continue;
			}
			for (j = (n - k + 1) / 2;j < (n + k + 1) / 2;j++)
			{
				ans += abs(P[i] - P[j]);
			}
		}
		ans = min(ans, ans1);
	}
	printf("%lld\n", ans);
	return 0;
}

