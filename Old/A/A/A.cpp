// A.cpp : Defines the entry point for the console application.
//

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

float p, q;

float dfs(int x, int y, int R, int C, set<pair<int, int>>s, vector<vector<char>>& grd)
{
	float a=0, b=0, c=0, d=0;
	pair<int, int>p;
	if (x - 1 >= 0 && x - 1 < R)
	{
		set<pair<int, int>> s1(s);
		p.first = x - 1;
		p.second = y;
		if (s1.find(p)==s1.end())
		{
			s1.insert(p);
			a = dfs(x - 1, y, R, C, s1, grd);
		}
		
	}





	return max(max(a, b), max(c, d));
}




int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	long T, lp;
	long long ans;
	cin >> T;

	int R, C, x, y, S, i, j;
	
	

	for (lp = 1;lp <= T;lp++)
	{
		cin >> R >> C >> x >> y >> S;
		
		cin >> p >> q;
		vector<vector<char>> grd(R, vector<char>(C));
		vector<vector<int>> iV(R, vector<int>(C));
		for (i = 0;i < R;i++)
			for (j = 0;j < C;j++)
				cin >> grd[i][j];





		cout << "Case #" << lp << ": " << ans << "\n";
	}
	return 0;
}