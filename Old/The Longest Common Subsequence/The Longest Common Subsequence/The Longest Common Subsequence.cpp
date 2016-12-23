// The Longest Common Subsequence.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence

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

	int N, M, i, j;
	cin >> N >> M;
	vector<int> a(N), b(M);
	for (i = 0;i < N;i++)
		cin >> a[i];
	for (i = 0;i < M;i++)
		cin >> b[i];
	vector<vector<int>> lcs(N + 1, vector<int>(M + 1, 0));



	for (i = 0;i <= N;i++)
	{
		for (j = 0;j <= M;j++)
		{







		}
	}








	return 0;
}
