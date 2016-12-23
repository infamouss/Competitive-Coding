// Way Out.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/problems/WOUT

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	int T;
	long long N, H, start, end, i;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%lld%lld", &N, &H);
		vector<long long> space(N + 1, 0);
		for (i = 0;i < N;i++)
		{
			scanf("%lld%lld", &start, &end);
			space[start]++;
			space[end + 1]--;
		}
		for (i = 1;i <= N;i++)
			space[i] += space[i - 1];
		vector<long long> mSpace(N + 1 - H);
		for (i = 0;i < H;i++)
			mSpace[0] += space[i];
		for (i = 1;i < N + 1 - H;i++)
		{
			mSpace[i] = mSpace[i - 1] + space[H-1 + i] - space[i - 1];
		}
		long long ans = mSpace[0];
		for (i = 1;i < N + 1 - H;i++)
			if (ans < mSpace[i])
				ans = mSpace[i];
		printf("%lld\n", N*H - ans);
	}
	return 0;
}

