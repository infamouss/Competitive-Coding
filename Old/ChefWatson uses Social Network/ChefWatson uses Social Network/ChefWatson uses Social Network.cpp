// ChefWatson uses Social Network.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COOK75/problems/BOOKCHEF

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


	int N, M, i;
	cin >> N >> M;
	set<long> id;
	long idd, p;
	for (i = 0;i < N;i++)
	{
		cin >> idd;
		id.insert(idd);
	}
	vector<pair<int, string>> frds, others;
	pair<int, string> tmp;
	for (i = 0;i < M;i++)
	{
		cin >> idd >> tmp.first >> tmp.second;
		if (id.find(idd) != id.end())
		{
			frds.push_back(tmp);
		}
		else
		{
			others.push_back(tmp);
		}
	}
	sort(frds.rbegin(), frds.rend());
	sort(others.rbegin(), others.rend());
	for (i = 0;i < frds.size();i++)
		cout << frds[i].second << "\n";
	for (i = 0;i < others.size();i++)
		cout << others[i].second << "\n";
	return 0;
}

