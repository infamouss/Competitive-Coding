// Bricks Game.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/play-game

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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	/*long T, lp;
	long long ans;
	cin >> T;
	for (lp = 1;lp <= T;lp++)
	{
	cout << "Case #" << lp << ": " << ans << "\n";
	}*/


	int T;
	cin >> T;
	while (T--)
	{
		long N, i, j;
		cin >> N;
		long long ans;
		vector<long long> a(N + 1), sum(N + 1);
		vector<long long> dp(N + 1);
		
		for (i = N;i > 0;i--)
		{
			cin >> a[i];
		}
		sum[0] = 0;
		for (i = 1;i <= N;i++)
			sum[i] = sum[i - 1] + a[i];

		dp[0] = 0;
		dp[1] = a[1];
		if (N >= 2)
		{
			dp[2] = dp[1] + a[2];
			if (N >= 3)
			{
				dp[3] = dp[2] + a[3];
			}
		}



		for (i = 4;i <= N;i++)
		{
			dp[i] = max(sum[i - 1] - dp[i - 1] + a[i], max(sum[i - 2] - dp[i - 2] + a[i] + a[i - 1], sum[i - 3] - dp[i - 3] + a[i] + a[i - 1] + a[i - 2]));
		}

		cout << dp[N] << "\n";



	}


	dp[i][j]=max(min(dp[j-1][k],positons[j-1]-positons[k]))
	i-j<=k<=j-1






	return 0;
}
