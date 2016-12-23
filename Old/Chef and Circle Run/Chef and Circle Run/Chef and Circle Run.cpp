// Chef and Circle Run.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/AUG16/problems/CHEFCRUN

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

long N, limU, limV;

long clk(long u, long v, vector<long>& wts)
{
	long retval;


	if (u == v)
	{
		if (wts[u] < 0)
		{
			return 2 * wts[u];
		}
		limV = v;
		return 0;
	}
	

	retval = clk((u + 1 + N) % N, v, wts) + 2 * wts[(u + N) % N];

	if (retval < 0)
	{
		return retval;
	}
	limV = u;
	return 0;


}


long aclk(long u, long v, vector<long>& wts)
{
	long retval;

	if (u == v)
	{
		if (wts[u] < 0)
		{
			return 2 * wts[u];
		}
		limU = u;
		return 0;
	}


	retval = clk((u - 1 + N) % N, v, wts) + 2 * wts[(u + N) % N];
	if (retval < 0)
	{
		return retval;
	}
	limU = u;
	return 0;

}



int main()
{
	int T;
	long i, u, v, c, a, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%ld", &N);
		vector<long> wts(N);
		for (i = 0;i < N;i++)
			scanf("%ld", &wts[i]);
		scanf("%ld%ld", &u, &v);
		u--;
		v--;
		//clockwise traversal anti regresstion
		for (i = u, c = 0;i != v;i = (i + 1) % N)
		{
			c += wts[(i + N) % N];
		}
		c += aclk(u, v, wts);
		c += clk(v, limU, wts);
		//anti treversal clockwise regresstin
		for (i = v, a = 0;i != u;i = (i + 1) % N)
		{
			a += wts[(i + N) % N];
		}
		a += clk(u, v, wts);
		a += aclk(v, limV, wts);

		ans = min(a, c);
		printf("%ld\n", ans);

	}
	return 0;
}

