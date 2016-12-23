// Roads and Libraries.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/world-codesprint-8/challenges/torque-and-development

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
#include <climits>
#include <unordered_map>

using namespace std;


long dfs(vector<vector<long>>& gph, long root, vector<bool>& isVisited)
{
	if (!isVisited[root])
	{
		isVisited[root] = true;
		long ans = 1, i;
		for (i = 0;i < gph[root].size();i++)
		{
			ans +=  dfs(gph, gph[root][i], isVisited);
		}
		return ans;
	}
	return 0;
}







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
		long n, m, l, r, i, x, y, ans = 0;
		cin >> n >> m >> l >> r;
		vector<vector <long>> gph(n);
		for (i = 0;i < m;i++)
		{
			cin >> x >> y;
			--x, --y;
			gph[x].push_back(y);
			gph[y].push_back(x);
		}
		vector<bool> isVisited(n, false);
		for (i = 0;i < n;i++)
		{
			long numNodes = dfs(gph, i, isVisited);
			if (numNodes)
			{
				ans += min((numNodes - 1)*r + l, numNodes*l);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

