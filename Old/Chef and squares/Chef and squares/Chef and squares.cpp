// Chef and squares.cpp : Defines the entry point for the console application.
// url : https://www.codechef.com/NOV16/problems/CHSQR

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
		int N, i, j, start;
		cin >> N;
		start = N - N / 2;
		for (i = 0;i < N;i++)
		{
			for (j = 0;j < N;j++)
			{
				cout << (start + j) % N + 1 << " ";
			}
			cout << "\n";
			start = (start + 1) % N;
		}
	}
	return 0;
}
