// Chef and Tetris.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/JULY16/problems/CHEFTET

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;
int ttime;
long A[100000], B[100000];
long defloration(int taken[])
{
	long retval;
	switch (ttime)
	{
	case 0:
		return A[0];
	case 1:
		taken[0] = 1;
		return A[0] + B[0];
	case 2:
		taken[1] = 1;
		return A[0] + B[1];
	case 3:
		taken[0] = taken[1] = 1;
		return A[0] + B[0] + B[1];
	}
}


int main()
{
	int T, i, N;
	long sum, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0;i < N;i++)
			scanf("%ld", &B[i]);
		for (i = 0;i < N;i++)
			scanf("%ld", &A[i]);
		ans = -1;
		if (N == 1)
			ans = A[0] + B[0];
		else
		{
			for (ttime = 0;ttime < 4;ttime++)
			{
				int taken[10000] = { 0 }, flag = 0;
				sum = defloration(taken);
				i = 1;
				while (i < N - 1 && flag == 0)
				{
					if (A[i] + B[i - 1] * ((taken[i - 1] + 1) % 2) == sum)
						taken[i - 1] = 1;
					else if (A[i] + B[i - 1] * ((taken[i - 1] + 1) % 2) + B[i] * ((taken[i] + 1) % 2) == sum)
						taken[i - 1] = taken[i] = 1;
					else if (A[i] + B[i - 1] * ((taken[i - 1] + 1) % 2) + B[i + 1] == sum)
						taken[i - 1] = taken[i + 1] = 1;
					else if (A[i] + B[i - 1] * ((taken[i - 1] + 1) % 2) + B[i] * ((taken[i] + 1) % 2) + B[i + 1] == sum)
						taken[i - 1] = taken[i] = taken[i + 1] = 1;
					else
						flag = 1;
					i++;
				}
				if (sum != A[N - 1] + B[N - 1] * ((taken[N - 1] + 1) % 2) + B[N - 2] * ((taken[N - 2] + 1) % 2))
					flag = 1;
				if (flag == 0 && sum > ans)
					ans = sum;
			}
		}
		printf("%ld\n", ans);
	}
	return 0;
}

