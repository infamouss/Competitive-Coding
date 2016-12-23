// CivilWar.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/COWS2016/problems/CVW

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
	long N, K, i, j;
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		if (K == 0)
		{
			for (i = 1;i <= N;i++)
				cout << i << " ";
		}
		else if (N % 2 != 0 || N%K != 0 || (N / K) % 2 != 0)
		{
			cout << "CAPTAIN AMERICA EVADES";
		}
		else
		{
			for (i = 1;i < N;i += 2 * K)
			{
				for (j = 1;j <= K;j++)
					cout << K + j + i - 1 << " ";
				for (j = 1;j <= K;j++)
					cout << i - 1 + j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
