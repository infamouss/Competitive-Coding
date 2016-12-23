// Lecture Notes.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/101hack41/challenges/lecture-notes

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
	int N, K, i, ans = 0;
	char ip[1001];
	cin >> N >> K;
	cin >> ip;
	int fds;
	for (i = 0;i < K;i++)
	{
		cin >> fds;
		if (ip[fds - 1] == '0' && ans == 0)
		{
			ans = 1;
		}
	}

	if (ans == 0)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
	}


	return 0;
}
