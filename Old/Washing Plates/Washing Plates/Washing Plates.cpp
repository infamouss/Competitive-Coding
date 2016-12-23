// Washing Plates.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/101hack41/challenges/washing-plates

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


	long N, K, i, j;
	long long ans = 0;
	long long c, d;
	cin >> N >> K;
	

	vector<long long> len(N);
	for (i = 0;i < N;i++)
	{
		cin >> c >> d;
		ans = ans - d;
		len[i] = c + d;
	}

	sort(len.rbegin(), len.rend());

	for (i = 0;i < K;i++)
	{
		ans = ans + len[i];
	}
		
	if (ans > 0)
	{
		cout << ans << "\n";
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
