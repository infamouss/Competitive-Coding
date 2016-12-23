// Coin on the Table.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/coin-on-the-table

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

#define INFI (1<<30)

long dp[1001][51][51];


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



	int N, M, K, i, j, k, x, y;
	char mat[52][52];
	cin >> N >> M >> K;
	for (i = 0;i < N;i++)
	{
		cin >> mat[i];
		for (j = 0;j < M;j++)
			if (mat[i][j] == '*')
			{
				x = i;
				y = j;
			}
	}
		

	for (k = 0;k <= K;k++)
	{
		for (i = 0;i < N;i++)
		{
			for (j = 0;j < M;j++)
			{
				if (k == 0)
				{
					dp[k][i][j] = ((i == 0 && j == 0) ? 0 : INFI);
				}
				else
				{
					long tmp = INFI;
					if (i > 0)
					{
						tmp = min(tmp, dp[k - 1][i - 1][j] + ((mat[i - 1][j] == 'D') ? 0 : 1));
					}
					if (i < N - 1)
					{
						tmp = min(tmp, dp[k - 1][i + 1][j] + ((mat[i + 1][j] == 'U') ? 0 : 1));
					}
					if (j > 0)
					{
						tmp = min(tmp, dp[k - 1][i][j - 1] + ((mat[i][j - 1] == 'R') ? 0 : 1));
					}
					if (j < M - 1)
					{
						tmp = min(tmp, dp[k - 1][i][j + 1] + ((mat[i][j + 1] == 'L') ? 0 : 1));
					}
					dp[k][i][j] = tmp;
				}
			}
		}
	}


	long ans = INFI;
	for (i = 0;i <= K;i++)
		ans = min(ans, dp[i][x][y]);
	if (ans < INFI)
		cout << ans << "\n";
	else
		cout << "-1\n";

	return 0;
}


