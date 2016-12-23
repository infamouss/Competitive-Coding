// Chef and cities.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JUNE16/problems/FRJUMP

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <functional>
#include <vector>
#include <cmath>

typedef unsigned long long lli;
#define lim 1000000007

lli arr[100000];

lli findLeadingDigit(lli N)
{
	while (N / 10 != 0)
	{
		N /= 10;
	}
	return N;
}




int main()
{
	long long N, Q, R, p, i;
	lli f, ans;
	int type;

	scanf("%lld", &N);
	for (i = 0;i < N;i++)
	{
		scanf("%llu", &arr[i]);
	}
	scanf("%lld", &Q);
	while (Q--)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%lld %llu", &p, &f);
			arr[p - 1] = f;
		}
		else
		{
			scanf("%lld", &R);
			ans = 1;
			i = 0;
			while (i < N)
			{
				ans = ans*arr[i];
				ans = ans%lim;
				i += R;
			}
			printf("%llu %llu\n", findLeadingDigit(ans), ans);
		}
	}
	return 0;
}

