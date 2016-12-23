// Variation.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/ZCOPRAC/problems/ZCO15002

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	long N, K, i, j;
	long long ans;
	scanf("%ld%ld", &N, &K);
	vector<long> ip(N);
	for (i = 0;i < N;i++)
	{
		scanf("%ld", &ip[i]);
	}
	ans = 0;
	sort(ip.begin(), ip.end());
	i = 0;
	j = 1;
	while (j < N&&i <= j)
	{
		while (j < N&&ip[j] - ip[i] < K)
		{
			j++;
		}
		if (j < N)
			ans += (N - j);
		i++;	
	}
	printf("%lld\n", ans);
	return 0;
}

