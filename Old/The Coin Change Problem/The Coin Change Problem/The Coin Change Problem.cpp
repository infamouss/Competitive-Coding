// The Coin Change Problem.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/coin-change

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


	int N, M, i, j;
	cin >> N >> M;
	vector<long long> dp(N + 1, 0), c(M);
	dp[0] = 1;
	for (i = 0;i < M;i++)
		cin >> c[i];
	for (i = 0;i < M;i++)
	{
		for (j = c[i];j <= N;j++)
		{
				dp[j] += dp[j - c[i]];
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
