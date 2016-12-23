// Lumpy - The Bus Driver.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/LTIME38/problems/LUMPYBUS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
	long T, N, i, ans;
	long long P, Q;
	scanf("%ld", &T);
	while (T--)
	{
		scanf("%ld %lld %lld", &N, &Q, &P);
		vector<long> rem(N + 1);
		for (i = 0;i < N;i++)
			scanf("%lld", &rem[i]);
		sort(rem.begin(), rem.end()-1);
		ans = 0;
		i = 0;
		while (i < N && 2 * P + Q >= rem[i])
		{
			if (rem[i] % 2 == 0)
			{
				if (2 * P >= rem[i])
				{
					P -= rem[i] / 2;
					ans++;
				}
				else
				{
					rem[i] -= 2 * P;
					P = 0;
					if (Q >= rem[i])
					{
						Q -= rem[i];
						ans++;
					}
				}
			}
			else
			{
				if (Q > 0)
				{
					Q--;
					rem[i]--;
					if (2 * P >= rem[i])
					{
						P -= rem[i] / 2;
						ans++;
					}
					else
					{
						rem[i] -= 2 * P;
						P = 0;
						if (Q >= rem[i])
						{
							Q -= rem[i];
							ans++;
						}
						else
						{
							Q++;
						}
					}
				}
			}
			i++;
		}
		printf("%ld\n", ans);
	}
	return 0;
}

