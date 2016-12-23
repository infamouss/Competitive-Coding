// Finding Hardest Sum Value.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/TSTIND16/problems/KOL15B

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

long N, M;
long arr[1000][1000], ans[1000][1000], a[1000], b[1000];


long dp[1000][1000][4];

int main()
{
	long T;
	cin >> T;
	while (T--)
	{
		
		scanf("%ld%ld", &N, &M);
		
		long i, j;
		for (i = 0;i < N;i++)
			for (j = 0;j < M;j++)
				scanf("%ld", &arr[i][j]);
		for (i = 0;i < N;i++)
		{
			for (j = 0;j < M;j++)
			{
				dp[i][j][0] = arr[i][j] + min((long)0, ((i - 1 < 0) ? 0 : dp[i - 1][j][0]));
				dp[i][j][2] = arr[i][j] + min((long)0, ((j - 1 < 0) ? 0 : dp[i][j - 1][2]));
			}
		}
		for (i = N-1;i >= 0;i--)
		{
			for (j = M - 1;j >= 0;j--)
			{
				dp[i][j][1] = arr[i][j] + min((long)0, ((i + 1 >= N) ? 0 : dp[i + 1][j][1]));
				dp[i][j][3] = arr[i][j] + min((long)0, ((j + 1 >= M) ? 0 : dp[i][j + 1][3]));
			}
		}
		long min = dp[0][0][0] + dp[0][0][1] + dp[0][0][2] + dp[0][0][3] - 3*arr[0][0];
		for (i = 0;i < N;i++)
			for (j = 0;j < M;j++)
			{
				
				if (dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3] - 3 * arr[i][j] < min)
					min = dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3] - 3 * arr[i][j];

			}
		printf("%ld\n", min);
	}
	return 0;
}
