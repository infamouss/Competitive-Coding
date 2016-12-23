// Chewing.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/ZCOPRAC/problems/ZCO13003

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
	long long ans = 0;
	scanf("%ld%ld", &N, &K);
	vector<long> ip(N);
	for (i = 0;i < N;i++)
	{
		scanf("%ld", &ip[i]);
	}
	sort(ip.begin(), ip.end());
	i = 0;
	j = N - 1;
	while (i < j)
	{
		if (ip[i] + ip[j] < K)
		{
			ans += j - i;
			i++;
		}
		else
		{
			j--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

