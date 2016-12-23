// Stock Maximize.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/stockmax

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
	long N, i;
	while (T--)
	{
		cin >> N;
		vector<long> prices(N);
		for (i = 0;i < N;i++)
			cin >> prices[i];
		vector<long> nMax(N);
		long mx = prices[N - 1], mn = prices[N - 1];
		for (i = N - 1;i >= 0;i--)
		{
			if (mx >= prices[i])
			{
				nMax[i] = mx;
			}
			else
			{
				nMax[i] = mx = prices[i];
			}
		}
		nMax.push_back(0);
		long numShares = 0, profit = 0;
		for (i = 0;i < N;i++)
		{

			if (prices[i] >= nMax[i + 1])//sell
			{
				profit += numShares*prices[i];
				numShares = 0;
			}
			else if (prices[i] <= nMax[i + 1])//buy
			{
				profit -= prices[i];
				numShares++;
			}
		}
		cout << profit << "\n";
	}
	return 0;
}

