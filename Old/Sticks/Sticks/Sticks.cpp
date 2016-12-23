// Sticks.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T; long ans;
	scanf("%d", &T);
	while (T--)
	{
		int sides[1001] = { 0 };
		int N, i, tmp, max, max2;
		max = max2 = -1;
		scanf("%d", &N);
		for (i = 0;i < N;i++)
		{
			scanf("%d", &tmp);
			sides[tmp]++;
		}
		for (i = 1000;i >= 0;i--)
		{
			if (sides[i] >= 4 && max == -1 && max2 == -1)
			{
				max = max2 = i;
			}
			else if (sides[i] >= 2)
			{
				if (max == -1)
				{
					max = i;
				}
				else if (max2 == -1)
				{
					max2 = i;
				}
			}
		}
		if (max2 == -1 || max == -1)
		{
			printf("-1\n");
		}
		else
		{
			ans = max*max2;
			printf("%ld\n", ans);
		}
	}
	return 0;
}

