// Chef and Round Run.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/AUG16/problems/CHEFRRUN

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>

using namespace std;

int main()
{
	long T, N, i, nxt, ans, pre, j;
	long long tmp;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%ld", &N);
		vector<long> ip(N), visited(N, 0);
		ans = 0;
		for (i = 0;i < N;i++)
		{
			scanf("%lld", &tmp);
			ip[i] = (i + tmp + 1) % N;
		}


		for (i = 0;i < N;i++)
		{
			j = i;
			set<long> present;
			while (present.find(j) == present.end() && visited[j] == 0)
			{
				present.insert(j);
				visited[j] = 1;
				j = ip[j];
			}
			if (present.find(j) != present.end() && visited[j] == 1)//LOOP
			{
				nxt = ip[j];
				while (nxt != j)
				{
					ans++;
					nxt = ip[nxt];
				}
				ans++;
			}
		}
		printf("%ld\n", ans);
	}
	return 0;
}

