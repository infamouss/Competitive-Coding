// Drumpf for President!.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME38/problems/STUDVOTE

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	int T, N, K, i, tmp, ans;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d%d", &N, &K);
		vector<int> votes(N + 1, 0);
		for (i = 1;i <= N;i++)
		{
			scanf("%d", &tmp);
			if (tmp == i)
				votes[i] = -1;
			if (votes[tmp] != -1)
				votes[tmp]++;
		}
		for (i = 1;i <= N;i++)
			if (votes[i] >= K)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}

