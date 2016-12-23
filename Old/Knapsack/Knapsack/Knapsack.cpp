// Knapsack.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/unbounded-knapsack

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
		int N, K, i, a, ans = 0;
		cin >> N >> K;
		set<int> arr;
		for (i = 0;i < N;i++)
		{
			cin >> a;
			arr.insert(a);
		}
		vector<int> dp(K + 1, 0);
		dp[0] = 1;
		for (i = 1;i <= K;i++)
		{
			for (set<int>::iterator it = arr.begin();it != arr.end() && i - *it >= 0 && dp[i] == 0;it++)
			{
				if (dp[i - *it] == 1)
				{
					dp[i] = 1;
					ans = i;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
