// Round Table.cpp : Defines the entry point for the console application.
// url ; https://www.codechef.com/ZCOPRAC/problems/ZCO12004

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	long N, i, ans = 0, odd, even;
	scanf("%ld", &N);
	if (N % 2 == 0)
	{
		for (i = 0;i < N;i += 2)
		{
			scanf("%ld%ld", &odd, &even);
			ans += min(odd, even);
		}
	}
	else if (N == 1)
	{
		scanf("%ld", &ans);
	}
	else if (N == 3)
	{
		scanf("%ld%ld%ld", &odd, &even, &ans);
		ans = min(ans, min(odd, even));
	}
	else
	{
		int taken1 = 0, takenN = 0;
		scanf("%ld%ld", &odd, &even);
		ans = min(even, odd);
		if (ans == odd)
			taken1 = 1;
		for (i = 2;i < N - 3;i+=2)
		{
			scanf("%ld%ld", &odd, &even);
			ans += min(even, odd);
		}
		scanf("%ld%ld", &odd, &even);
		ans += min(even, odd);
		if (min(even, odd) == even)
		{
			takenN = 1;
		}
		scanf("%ld", &odd);
		if (taken1 == 0 && takenN == 0)
		{
			ans += odd;
		}


	}


	printf("%ld\n", ans);
	return 0;
}

